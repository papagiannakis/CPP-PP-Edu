project(chapter15)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.15.2-1 chapter.15.2-1.cpp)
add_executable(chapter.15.5 chapter.15.5.cpp)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

# ------------------------------------------------------------------------------------------
target_include_directories(chapter.15.2-1 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)
target_link_directories(chapter.15.2-1 PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)

target_link_libraries(chapter.15.2-1 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.15.2-1 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------
target_include_directories(chapter.15.5  PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)


target_link_libraries(chapter.15.5  PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.15.5  PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")