project(PPP2)
cmake_minimum_required(VERSION 3.1.4)


# set (CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

#FIND_PACKAGE(FLTK REQUIRED)
#FIND_PACKAGE(OpenGL REQUIRED)


add_subdirectory(Chapter02)

add_subdirectory(Chapter03)

add_subdirectory(Chapter04)

add_subdirectory(Chapter05)

add_subdirectory(Chapter08)

add_subdirectory(Chapter09)

add_subdirectory(Chapter10)

add_subdirectory(Chapter11)

add_subdirectory(fltk-1.3.5)

add_subdirectory(GUI)

add_subdirectory(Chapter12)

add_subdirectory(Chapter13)

add_subdirectory(Chapter14)

add_subdirectory(Chapter15)

add_subdirectory(Chapter16)

add_subdirectory(Chapter17)

add_subdirectory(Chapter18)

add_subdirectory(Chapter19)

add_subdirectory(Chapter20)

add_subdirectory(Chapter21)

add_subdirectory(Chapter24)

add_subdirectory(Chapter25)

add_subdirectory(Chapter26)

add_subdirectory(Chapter27)

add_subdirectory(_helloWorld_ray_tracing)