project(hellowWorldFLTK)
cmake_minimum_required(VERSION 3.1.4)


# set (CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)



add_subdirectory(fltk-1.3.5)

add_subdirectory(GUI)

add_subdirectory(Chapter12)
