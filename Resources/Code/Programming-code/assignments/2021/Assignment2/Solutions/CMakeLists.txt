project(assignment2)

cmake_minimum_required(VERSION 3.1.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(HEADER_FILES Ex4/MathLibrary/MathLibrary.h)
set(SOURCE_FILES Ex4/MathLibrary/MathLibrary.cpp)

add_library(mathlib ${HEADER_FILES} ${SOURCE_FILES})

add_executable(RecusrsiveSearchEx1 Ex1/Exercise1.cpp)
add_executable(RectangleEx2 Ex2/Exercise2.cpp)
add_executable(LibraryEx3 Ex3/Exercise3.cpp)
add_executable(StaticLibraryEx4 Ex4/Exercise4.cpp)

target_include_directories(StaticLibraryEx4 PUBLIC Ex4/MathLibrary)
target_link_directories(StaticLibraryEx4 PUBLIC Ex4/MathLibrary)

target_link_libraries(StaticLibraryEx4 PUBLIC mathlib)
