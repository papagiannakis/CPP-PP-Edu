cmake_minimum_required(VERSION 3.1.4)

project(Assignment1-2023)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(${PROJECT_NAME}.exe HY150_Ass1.cpp)