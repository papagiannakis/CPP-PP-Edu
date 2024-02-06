project(chapter25)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.25.4.1 chapter.25.4.1.cpp)
add_executable(chapter.25.7 chapter.25.7.cpp)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")