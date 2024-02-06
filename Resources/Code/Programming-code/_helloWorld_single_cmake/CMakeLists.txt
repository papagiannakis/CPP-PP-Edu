project(helloWorld_single)

cmake_minimum_required(VERSION 3.1.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(HelloWorld.exe HelloWorld.cpp)
add_executable(HelloWorld2.exe HelloWorld2.cpp)
