project(assignment1)

cmake_minimum_required(VERSION 3.1.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(VectorMagnitude Ex1/Exercise1.cpp)
add_executable(StringMerging Ex2/Exercise2.cpp)
add_executable(Projection Ex3/Exercise3.cpp)
add_executable(ValidParentheses Ex4/Exercise4.cpp)
add_executable(CoinExchange Ex5/Exercise5.cpp)
