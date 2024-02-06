project(chapter26)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.26.3.2.2 chapter.26.3.2.2.cpp)
add_executable(chapter.26.6 chapter.26.6.cpp)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")