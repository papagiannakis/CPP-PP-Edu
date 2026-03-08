cmake_minimum_required(VERSION 3.10)

project(helloWorld_single)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(HelloWorld.exe HelloWorld.cpp)
add_executable(HelloWorld2.exe HelloWorld2.cpp)
