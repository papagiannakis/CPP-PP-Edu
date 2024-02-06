cmake_minimum_required(VERSION 3.1.4)

project(Chrono-chapter9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(Chrono)

add_executable(${PROJECT_NAME}.exe chapter.9.8.cpp)

target_include_directories(${PROJECT_NAME}.exe PUBLIC Chrono)

target_link_directories(${PROJECT_NAME}.exe PUBLIC Chrono)

target_link_libraries(${PROJECT_NAME}.exe ChronoLib)