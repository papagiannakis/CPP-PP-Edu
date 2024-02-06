project(Ass04Solutions)

cmake_minimum_required(VERSION 3.1.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(SOURCE
   ${SOURCE}
   Ass04Solutions/CovidMutation1.cpp
   Ass04Solutions/CovidMutation2.cpp
   Ass04Solutions/Test.cpp
)


add_executable(Ass04Solutions ${SOURCE})
