project(GUI)

cmake_minimum_required(VERSION 3.1.5)

set(HEADER_FILES Graph.h GUI.h Point.h Simple_window.h Window.h std_lib_facilities.h)
set(SOURCE_FILES Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

add_library(bookgui STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(bookgui PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5/ ${CMAKE_BINARY_DIR}/fltk-1.3.5)
