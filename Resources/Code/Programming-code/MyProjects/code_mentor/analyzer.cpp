//
// analyzer.cpp
// code_mentor - CPP-PP-Edu Code Mentor Tool
//
// Implements the Analyzer class: file loading, parsing, metric computation,
// warning detection, and concept detection.
//

#include "analyzer.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include <cctype>
#include <stdexcept>

// ---------------------------------------------------------------------------
// Helpers (file-local)
// ---------------------------------------------------------------------------

namespace {

// Return a copy of s with leading and trailing whitespace removed.
std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Extract the base filename from a full path.
std::string base_name(const std::string& path) {
    auto pos = path.find_last_of("/\\");
    if (pos == std::string::npos) return path;
    return path.substr(pos + 1);
}

// Keywords that look like function calls but are NOT function definitions.
bool is_keyword_call(const std::string& token) {
    static const std::vector<std::string> kw = {
        "if", "for", "while", "switch", "return", "catch", "else", "do"
    };
    return std::find(kw.begin(), kw.end(), token) != kw.end();
}

// Remove characters inside string literals from a line (to avoid false braces).
// Very simple: strips content between unescaped double-quotes on the same line.
std::string strip_string_literals(const std::string& line) {
    std::string result;
    result.reserve(line.size());
    bool in_string = false;
    for (std::size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (in_string) {
            if (c == '\\') {
                ++i;            // skip escaped character
            } else if (c == '"') {
                in_string = false;
            }
            // characters inside the string are dropped
        } else {
            if (c == '"') {
                in_string = true;
            } else {
                result += c;
            }
        }
    }
    return result;
}

// Remove a // line-comment suffix from a (possibly already stripped) line.
std::string strip_line_comment(const std::string& line) {
    // Find // that is not inside a string literal.
    // We call strip_string_literals first and then just search for //
    // in the result, but we need the original for nesting counting.
    // Here we just want to skip characters after //.
    bool in_string = false;
    for (std::size_t i = 0; i + 1 < line.size(); ++i) {
        char c = line[i];
        if (in_string) {
            if (c == '\\') { ++i; }
            else if (c == '"') { in_string = false; }
        } else {
            if (c == '"') { in_string = true; }
            else if (c == '/' && line[i+1] == '/') {
                return line.substr(0, i);
            }
        }
    }
    return line;
}

} // anonymous namespace

// ---------------------------------------------------------------------------
// Analyzer implementation
// ---------------------------------------------------------------------------

Analyzer::Analyzer(const std::string& file_path)
    : file_path_(file_path)
{}

AnalysisResult Analyzer::analyze() {
    load_file();

    AnalysisResult result;
    result.file_path       = file_path_;
    result.file_name       = base_name(file_path_);
    result.chapter_number  = infer_chapter();
    result.uses_namespace_std = false;

    parse_includes (result);
    parse_functions(result);
    compute_metrics(result);
    detect_warnings(result);
    detect_concepts(result);

    return result;
}

// ---------------------------------------------------------------------------
// Private helpers
// ---------------------------------------------------------------------------

void Analyzer::load_file() {
    std::ifstream in(file_path_);
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open file: " + file_path_);
    }
    std::string line;
    while (std::getline(in, line)) {
        lines_.push_back(line);
    }
}

int Analyzer::infer_chapter() const {
    // Patterns: Chapter05, chapter.5, Ch05, ch5, Chapter5 etc.
    static const std::vector<std::regex> patterns = {
        std::regex(R"([Cc]hapter[._\s]?(\d+))",   std::regex::icase),
        std::regex(R"([Cc]h[._\s]?(\d+))",        std::regex::icase),
    };
    for (auto& re : patterns) {
        std::smatch m;
        if (std::regex_search(file_path_, m, re)) {
            try { return std::stoi(m[1].str()); }
            catch (...) {}
        }
    }
    return -1;
}

void Analyzer::parse_includes(AnalysisResult& r) const {
    for (auto& line : lines_) {
        std::string t = trim(line);
        if (t.substr(0, 8) == "#include") {
            std::string rest = trim(t.substr(8));
            if (!rest.empty()) {
                r.includes.push_back(rest);
            }
        }
    }
}

void Analyzer::parse_functions(AnalysisResult& r) const {
    // Simple heuristic function-definition detector.
    // A line is a candidate if:
    //   - It contains '(' and ')'
    //   - It does NOT start with # (preprocessor)
    //   - The first non-whitespace token is NOT a keyword call
    //   - The line does NOT start with // or is inside a block comment

    bool in_block_comment = false;

    for (int i = 0; i < static_cast<int>(lines_.size()); ++i) {
        const std::string& raw = lines_[i];
        std::string t = trim(raw);

        // Track block comments
        if (!in_block_comment) {
            auto bc = t.find("/*");
            if (bc != std::string::npos) {
                // Check if it closes on the same line
                auto ec = t.find("*/", bc + 2);
                if (ec == std::string::npos) {
                    in_block_comment = true;
                }
                continue;
            }
        } else {
            if (t.find("*/") != std::string::npos) {
                in_block_comment = false;
            }
            continue;
        }

        // Skip line comments, preprocessor, and empty lines
        if (t.empty() || t[0] == '#') continue;
        if (t.size() >= 2 && t[0] == '/' && t[1] == '/') continue;

        // Must contain both '(' and ')'
        auto paren_open  = t.find('(');
        auto paren_close = t.find(')');
        if (paren_open == std::string::npos || paren_close == std::string::npos) continue;
        if (paren_open >= paren_close) continue;

        // Tokenize up to the first '('
        std::string before_paren = t.substr(0, paren_open);
        std::istringstream ss(before_paren);
        std::vector<std::string> tokens;
        std::string tok;
        while (ss >> tok) tokens.push_back(tok);

        if (tokens.empty()) continue;

        // The last token before '(' is the function name
        std::string func_name = tokens.back();
        // The tokens before that form the return type
        std::string return_type;
        for (std::size_t j = 0; j + 1 < tokens.size(); ++j) {
            if (j > 0) return_type += " ";
            return_type += tokens[j];
        }
        if (return_type.empty()) return_type = tokens[0]; // bare name (constructor?)

        // Skip keyword calls
        if (is_keyword_call(func_name)) continue;

        // Skip if function name contains operators or non-identifier chars
        // (catches assignments, initialisers like a(b))
        bool valid = !func_name.empty();
        for (char c : func_name) {
            if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_') {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        // Require that the next non-whitespace character after ')' is '{' or ';' or newline
        // (or the closing paren is followed by nothing useful — skip '=' assignments)
        // To detect definitions (not declarations), look for '{' somewhere after
        // the closing ')' (on same or next few lines).
        std::string after_paren = trim(t.substr(paren_close + 1));
        // Strip any trailing qualifiers: const, noexcept, override, final
        // If the remainder starts with = or , it's not a definition
        if (!after_paren.empty() && (after_paren[0] == '=' || after_paren[0] == ',')) continue;

        // Extract params
        std::string params = t.substr(paren_open + 1, paren_close - paren_open - 1);

        // Check: does a '{' appear within the next 5 lines?
        bool has_body = false;
        for (int k = i; k < std::min(i + 6, static_cast<int>(lines_.size())); ++k) {
            std::string lk = strip_string_literals(strip_line_comment(lines_[k]));
            if (lk.find('{') != std::string::npos) { has_body = true; break; }
        }
        if (!has_body) continue;

        FunctionInfo fi;
        fi.return_type  = (tokens.size() > 1) ? return_type : "";
        fi.name         = func_name;
        fi.params       = trim(params);
        fi.line_number  = i + 1; // 1-based
        r.functions.push_back(fi);
    }
}

void Analyzer::compute_metrics(AnalysisResult& r) const {
    r.total_lines    = static_cast<int>(lines_.size());
    r.comment_lines  = 0;
    r.code_lines     = 0;
    r.deepest_nesting = 0;

    bool in_block_comment = false;
    int  current_depth    = 0;

    for (auto& raw : lines_) {
        std::string t = trim(raw);

        // Classify line as comment, blank, or code
        if (in_block_comment) {
            r.comment_lines++;
            if (t.find("*/") != std::string::npos) {
                in_block_comment = false;
            }
            continue;
        }

        if (t.empty()) continue; // blank — not counted as code or comment

        if (t.size() >= 2 && t[0] == '/' && t[1] == '/') {
            r.comment_lines++;
            continue;
        }

        if (t.find("/*") != std::string::npos) {
            r.comment_lines++;
            if (t.find("*/") == std::string::npos) {
                in_block_comment = true;
            }
            continue;
        }

        r.code_lines++;

        // Count braces for nesting depth
        // Strip string literals and line comments first
        std::string safe = strip_string_literals(strip_line_comment(raw));
        for (char c : safe) {
            if      (c == '{') { ++current_depth; }
            else if (c == '}') { --current_depth; if (current_depth < 0) current_depth = 0; }
        }
        if (current_depth > r.deepest_nesting) {
            r.deepest_nesting = current_depth;
        }
    }
}

void Analyzer::detect_warnings(AnalysisResult& r) const {
    // W: using namespace std
    for (int i = 0; i < static_cast<int>(lines_.size()); ++i) {
        std::string t = trim(lines_[i]);
        if (t.find("using namespace std") != std::string::npos) {
            r.uses_namespace_std = true;
            r.warnings.push_back("Line " + std::to_string(i + 1) +
                ": 'using namespace std' found. Stroustrup recommends avoiding "
                "it to prevent name collisions.");
        }
    }

    // W: raw loops (for/while without range-for colon)
    for (int i = 0; i < static_cast<int>(lines_.size()); ++i) {
        std::string t = trim(lines_[i]);
        // Skip comment lines
        if (t.size() >= 2 && t[0] == '/' && t[1] == '/') continue;

        auto for_pos   = t.find("for (");
        auto while_pos = t.find("while (");
        if (for_pos != std::string::npos) {
            // Range-for has ':' inside the loop header
            auto popen  = t.find('(', for_pos);
            auto pclose = t.find(')', popen != std::string::npos ? popen : 0);
            if (popen != std::string::npos && pclose != std::string::npos) {
                std::string header = t.substr(popen, pclose - popen);
                if (header.find(':') == std::string::npos) {
                    r.warnings.push_back("Line " + std::to_string(i + 1) +
                        ": Raw loop detected. Consider if a range-for would be clearer.");
                }
            }
        } else if (while_pos != std::string::npos) {
            r.warnings.push_back("Line " + std::to_string(i + 1) +
                ": Raw loop (while) detected. Ensure loop bounds are correct.");
        }
    }

    // W: magic numbers
    // Look for numeric literals > 1 that are not in const/constexpr lines
    static const std::regex magic_re(R"(\b([2-9]\d*|[1-9]\d+)(\.\d+)?\b)");
    for (int i = 0; i < static_cast<int>(lines_.size()); ++i) {
        std::string t = trim(lines_[i]);
        if (t.size() >= 2 && t[0] == '/' && t[1] == '/') continue;
        if (t.find("const") != std::string::npos) continue;   // const declaration
        if (t.find("#define") != std::string::npos) continue; // macro definition

        // Strip string literals before searching for magic numbers
        std::string safe = strip_string_literals(t);
        std::sregex_iterator it(safe.begin(), safe.end(), magic_re);
        std::sregex_iterator end;
        if (it != end) {
            r.warnings.push_back("Line " + std::to_string(i + 1) +
                ": Magic number detected (" + it->str() +
                "). Consider naming numeric literals as named constants.");
            // Only warn once per line to avoid noise
        }
    }

    // W: no input validation for functions taking numeric parameters
    bool has_numeric_param = false;
    bool has_validation    = false;
    for (auto& fi : r.functions) {
        if (fi.params.find("int") != std::string::npos ||
            fi.params.find("double") != std::string::npos ||
            fi.params.find("float") != std::string::npos) {
            has_numeric_param = true;
        }
    }
    for (auto& line : lines_) {
        std::string t = trim(line);
        if (t.find("if (") != std::string::npos || t.find("assert") != std::string::npos) {
            has_validation = true;
        }
    }
    if (has_numeric_param && !has_validation) {
        r.warnings.push_back("No input validation found — functions take numeric "
            "parameters but no bounds check (if/assert) was detected.");
    }
}

void Analyzer::detect_concepts(AnalysisResult& r) const {
    // Join all lines into a single string for simple text search
    std::string full_text;
    for (auto& l : lines_) { full_text += l + "\n"; }

    r.concepts["#include usage"]    = !r.includes.empty();
    r.concepts["function definition"] = !r.functions.empty();

    // range-for: for ( ... : ... )
    {
        static const std::regex rfor(R"(for\s*\([^)]*:[^)]*\))");
        r.concepts["range-for"] = std::regex_search(full_text, rfor);
    }

    // references: & in a parameter list
    {
        bool found = false;
        for (auto& fi : r.functions) {
            if (fi.params.find('&') != std::string::npos) { found = true; break; }
        }
        r.concepts["references"] = found;
    }

    // vectors
    r.concepts["vectors"] = (full_text.find("vector<") != std::string::npos);

    // while-loop
    r.concepts["while-loop"] = (full_text.find("while (") != std::string::npos ||
                                full_text.find("while(") != std::string::npos);

    // for-loop
    r.concepts["for-loop"] = (full_text.find("for (") != std::string::npos ||
                              full_text.find("for(") != std::string::npos);
}
