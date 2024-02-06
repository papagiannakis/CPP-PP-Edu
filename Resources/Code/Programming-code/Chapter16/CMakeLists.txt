project(chapter16)

cmake_minimum_required(VERSION 3.1.4)

#add_dependencies()
add_executable(chapter.16.5 chapter.16.5.cpp)
add_executable(chapter.16.7 chapter.16.7.cpp)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

# ------------------------------------------------------------------------------------------
# LINK Chapter.16.5. with GUI & FLTK
target_include_directories(chapter.16.5 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)
target_link_directories(chapter.16.5 PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)

target_link_libraries(chapter.16.5 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.16.5 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------
# LINK Chapter.16.7
target_include_directories(chapter.16.7 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)

target_link_libraries(chapter.16.7 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(chapter.16.7 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")