project(chapter20)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.20.1.1 chapter.20.1.1.cpp)
add_executable(chapter.20.7.1 chapter.20.7.1.cpp)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")