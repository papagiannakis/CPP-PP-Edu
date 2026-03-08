//
// analyzer.h
// code_mentor - CPP-PP-Edu Code Mentor Tool
//
// Declares FunctionInfo, AnalysisResult structs and the Analyzer class.
//

#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include <vector>
#include <map>

// ---------------------------------------------------------------------------
// Data structures
// ---------------------------------------------------------------------------

struct FunctionInfo {
    std::string return_type;
    std::string name;
    std::string params;
    int         line_number;
};

struct AnalysisResult {
    std::string file_path;
    std::string file_name;
    int         chapter_number;   // -1 if not inferrable

    int total_lines;
    int comment_lines;
    int code_lines;
    int deepest_nesting;

    std::vector<FunctionInfo>  functions;
    std::vector<std::string>   includes;
    std::vector<std::string>   warnings;
    std::map<std::string, bool> concepts;   // e.g. {"range-for", true}
    bool uses_namespace_std;
};

// ---------------------------------------------------------------------------
// Analyzer class
// ---------------------------------------------------------------------------

class Analyzer {
public:
    explicit Analyzer(const std::string& file_path);

    AnalysisResult analyze();

private:
    std::string              file_path_;
    std::vector<std::string> lines_;

    void load_file();
    int  infer_chapter()                        const;
    void parse_includes  (AnalysisResult& r)    const;
    void parse_functions (AnalysisResult& r)    const;
    void compute_metrics (AnalysisResult& r)    const;
    void detect_warnings (AnalysisResult& r)    const;
    void detect_concepts (AnalysisResult& r)    const;
};

#endif // ANALYZER_H
