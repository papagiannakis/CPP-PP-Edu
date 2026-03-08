cmake_minimum_required(VERSION 3.10)
project(code_mentor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code_mentor.exe
    code_mentor.cpp
    analyzer.cpp
    reporter.cpp
)
