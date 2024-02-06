project(Chapter-GUI-assignment-2021)

cmake_minimum_required(VERSION 3.1.4)

#add_dependencies()
add_executable(LinearRegression exercise1.cpp)
add_executable(Carousel exercise2.cpp)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

# ------------------------------------------------------------------------------------------
# LINK Chapter.12.3. with GUI & FLTK
target_include_directories(LinearRegression PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)
target_link_directories(LinearRegression PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)

target_link_libraries(LinearRegression PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(LinearRegression PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

# ------------------------------------------------------------------------------------------
# LINK Chapter.12.7.11.
target_include_directories(Carousel PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)

target_link_libraries(Carousel PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(Carousel PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")