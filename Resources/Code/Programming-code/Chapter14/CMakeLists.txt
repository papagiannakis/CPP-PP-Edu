project(chapter14)

cmake_minimum_required(VERSION 3.1.4)

add_executable(chapter.14.2.4 chapter.14.2.4.cpp)
add_executable(chapter.14.3.3 chapter.14.3.3.cpp)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

# ------------------------------------------------------------------------------------------
target_include_directories(chapter.14.2.4 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)
target_link_directories(chapter.14.2.4 PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)


target_link_libraries(chapter.14.2.4 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.14.2.4 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------
target_include_directories(chapter.14.3.3 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)

target_link_libraries(chapter.14.3.3 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.14.3.3 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")