project(chapter18)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.18.2.1 chapter.18.2.1.cpp)
add_executable(chapter.18.6.3-2 chapter.18.6.3-2.cpp)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")
