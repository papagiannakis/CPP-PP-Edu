project(helloWorld_unit_testing)
cmake_minimum_required(VERSION 3.1.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# you need to do: "git clone git@github.com:google/googletest.git"
# so that you get the googletest project in this folder
# which is build also via cmake

add_subdirectory(googletest)

include_directories(googletest/include)


add_executable(mytests.exe mytests.cpp)
target_link_libraries(mytests.exe PRIVATE gtest)

add_executable(${PROJECT_NAME}.exe chapter.5.6.1.cpp)


