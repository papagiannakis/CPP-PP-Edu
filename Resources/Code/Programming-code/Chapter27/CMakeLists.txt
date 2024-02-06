project(chapter27)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.27.2.3 chapter.27.2.3.cpp)
add_executable(chapter.27.6.3 chapter.27.6.3.cpp)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")