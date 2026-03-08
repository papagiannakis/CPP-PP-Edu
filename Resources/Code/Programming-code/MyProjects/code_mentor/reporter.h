//
// reporter.h
// code_mentor - CPP-PP-Edu Code Mentor Tool
//
// Declares the Reporter class that formats and outputs the AnalysisResult.
//

#ifndef REPORTER_H
#define REPORTER_H

#include "analyzer.h"
#include <string>
#include <ostream>

class Reporter {
public:
    explicit Reporter(const AnalysisResult& result);

    void print_to_console()                             const;
    void save_to_file(const std::string& output_path)  const;

private:
    const AnalysisResult& result_;
    void write_report(std::ostream& out) const;
};

#endif // REPORTER_H
