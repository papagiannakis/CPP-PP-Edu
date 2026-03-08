//
// reporter.cpp
// code_mentor - CPP-PP-Edu Code Mentor Tool
//
// Implements the Reporter class.  A single write_report() method drives
// both console output and file output by accepting a std::ostream&.
//

#include "reporter.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

Reporter::Reporter(const AnalysisResult& result)
    : result_(result)
{}

// ---------------------------------------------------------------------------
// Public interface
// ---------------------------------------------------------------------------

void Reporter::print_to_console() const {
    write_report(std::cout);
}

void Reporter::save_to_file(const std::string& output_path) const {
    std::ofstream out(output_path);
    if (!out.is_open()) {
        std::cerr << "Warning: could not write report to " << output_path << "\n";
        return;
    }
    write_report(out);
    std::cout << "\nReport saved to: " << output_path << "\n";
}

// ---------------------------------------------------------------------------
// Core formatting
// ---------------------------------------------------------------------------

void Reporter::write_report(std::ostream& out) const {
    const int W1 = 20;   // label column width
    const AnalysisResult& r = result_;

    // -----------------------------------------------------------------------
    // Header
    // -----------------------------------------------------------------------
    out << "\n=== CPP-PP-Edu Code Mentor Report ===\n";
    out << std::left << std::setw(W1) << "File"
        << ": " << r.file_name << "\n";

    if (r.chapter_number > 0) {
        out << std::left << std::setw(W1) << "Chapter"
            << ": " << r.chapter_number
            << " (inferred from path)\n";
    } else {
        out << std::left << std::setw(W1) << "Chapter"
            << ": (could not be inferred)\n";
    }

    // -----------------------------------------------------------------------
    // Structure summary
    // -----------------------------------------------------------------------
    out << "\n--- Structure Summary ---\n";
    out << std::left << std::setw(W1) << "Functions found"
        << ": " << r.functions.size() << "\n";

    for (auto& fi : r.functions) {
        std::string sig = fi.return_type.empty()
            ? fi.name + "(" + fi.params + ")"
            : fi.return_type + " " + fi.name + "(" + fi.params + ")";
        out << "  - " << sig << "\n";
    }

    out << "\n";
    out << std::left << std::setw(W1) << "Includes detected"
        << ": " << r.includes.size() << "\n";
    for (auto& inc : r.includes) {
        out << "  - " << inc << "\n";
    }

    // -----------------------------------------------------------------------
    // Complexity metrics
    // -----------------------------------------------------------------------
    out << "\n--- Complexity Metrics ---\n";
    out << std::left << std::setw(W1) << "Lines of code"
        << ": " << r.total_lines << "\n";

    int comment_pct = 0;
    if (r.total_lines > 0) {
        comment_pct = static_cast<int>(
            std::round(100.0 * r.comment_lines / r.total_lines));
    }
    out << std::left << std::setw(W1) << "Comment density"
        << ": " << comment_pct << "%"
        << "  (" << r.comment_lines << " comment lines)\n";

    out << std::left << std::setw(W1) << "Deepest nesting"
        << ": " << r.deepest_nesting << "\n";

    // -----------------------------------------------------------------------
    // Beginner warnings
    // -----------------------------------------------------------------------
    out << "\n--- Beginner Warnings ---\n";
    if (r.warnings.empty()) {
        out << "(No warnings detected)\n";
    } else {
        for (std::size_t i = 0; i < r.warnings.size(); ++i) {
            out << "[W" << (i + 1) << "] " << r.warnings[i] << "\n";
        }
    }

    // -----------------------------------------------------------------------
    // Chapter concepts
    // -----------------------------------------------------------------------
    out << "\n--- Chapter Concepts Detected ---\n";

    // Define the expected concepts and a simple chapter hint for each
    struct ConceptEntry {
        std::string key;
        std::string label;
        std::string hint;           // shown if MISSING
    };

    static const std::vector<ConceptEntry> expected = {
        { "#include usage",      "#include usage",       "Ch. 2"  },
        { "function definition", "Function definition",  "Ch. 4"  },
        { "while-loop",          "while-loop",           "Ch. 4"  },
        { "for-loop",            "for-loop",             "Ch. 4"  },
        { "range-for",           "range-for",            "Ch. 4+" },
        { "vectors",             "Vectors (vector<T>)",  "Ch. 4+" },
        { "references",          "References (&)",       "Ch. 8"  },
    };

    for (auto& ce : expected) {
        auto it = r.concepts.find(ce.key);
        bool present = (it != r.concepts.end() && it->second);
        if (present) {
            out << "[OK]      " << ce.label
                << " (" << ce.hint << ")\n";
        } else {
            out << "[MISSING] " << ce.label
                << " — not detected in this file (expected in " << ce.hint << "+)\n";
        }
    }
}
