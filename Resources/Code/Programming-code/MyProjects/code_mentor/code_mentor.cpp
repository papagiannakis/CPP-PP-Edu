//
// code_mentor.cpp
// code_mentor - CPP-PP-Edu Code Mentor Tool
//
// Entry point.  Reads a .cpp source file, runs analysis, and prints +
// saves a structured report.
//

#include "analyzer.h"
#include "reporter.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: code_mentor <path-to-cpp-file> [output-report.txt]\n";
        return 1;
    }

    std::string input_file  = argv[1];
    std::string output_file = (argc >= 3) ? argv[2] : "code_mentor_report.txt";

    try {
        Analyzer       analyzer(input_file);
        AnalysisResult result  = analyzer.analyze();

        Reporter       reporter(result);
        reporter.print_to_console();
        reporter.save_to_file(output_file);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
