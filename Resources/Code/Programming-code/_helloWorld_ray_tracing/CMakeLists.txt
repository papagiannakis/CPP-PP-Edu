#---------------------------------------------------------------------------------------------------
# CMake Build Configuration for the helloWorld of Ray-tracing example
#
#
# See README.md for guidance.
# Files are repeated as they are being extended and modified as we progress through the book.
#
# @author Dr. George Papagiannakis
# @date 2024
#---------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.1.4...3.27.0)

project(helloWorld_ray_tracing)

# Set to C++11
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

# set source files
set ( SOURCE_FILES22
    src/InOneWeekend/Chapter2.2/rt1-chapter2.2.cpp
)

set ( SOURCE_FILES23
    src/InOneWeekend/Chapter2.3/rt1-chapter2.3.cpp
)

set ( SOURCE_FILES31
    src/InOneWeekend/Chapter3.1/vec3.h
    src/InOneWeekend/Chapter3.1/color.h
    src/InOneWeekend/Chapter3.1/rt1-chapter3.1.cpp
)

set ( SOURCE_FILES42
    src/InOneWeekend/Chapter4.2/vec3.h
    src/InOneWeekend/Chapter4.2/color.h
    src/InOneWeekend/Chapter4.2/ray.h
    src/InOneWeekend/Chapter4.2/rt1-chapter4.2.cpp
)

set ( SOURCE_FILES52
    src/InOneWeekend/Chapter5.2/vec3.h
    src/InOneWeekend/Chapter5.2/color.h
    src/InOneWeekend/Chapter5.2/ray.h
    src/InOneWeekend/Chapter5.2/rt1-chapter5.2.cpp
)

set ( SOURCE_FILES62
    src/InOneWeekend/Chapter6.2/vec3.h
    src/InOneWeekend/Chapter6.2/color.h
    src/InOneWeekend/Chapter6.2/ray.h
    src/InOneWeekend/Chapter6.2/rt1-chapter6.2.cpp
)

set ( SOURCE_FILES68
    src/InOneWeekend/Chapter6.8/vec3.h
    src/InOneWeekend/Chapter6.8/color.h
    src/InOneWeekend/Chapter6.8/ray.h
    src/InOneWeekend/Chapter6.8/rtweekend.h
    src/InOneWeekend/Chapter6.8/sphere.h
    src/InOneWeekend/Chapter6.8/hittable.h
    src/InOneWeekend/Chapter6.8/interval.h
    src/InOneWeekend/Chapter6.8/hittable_list.h
    src/InOneWeekend/Chapter6.8/rt1-chapter6.8.cpp
)

set ( SOURCE_FILES7
    src/InOneWeekend/Chapter7/vec3.h
    src/InOneWeekend/Chapter7/color.h
    src/InOneWeekend/Chapter7/ray.h
    src/InOneWeekend/Chapter7/rtweekend.h
    src/InOneWeekend/Chapter7/sphere.h
    src/InOneWeekend/Chapter7/hittable.h
    src/InOneWeekend/Chapter7/interval.h
    src/InOneWeekend/Chapter7/hittable_list.h
    src/InOneWeekend/Chapter7/rt1-chapter7.cpp
)

set ( SOURCE_FILES8
    src/InOneWeekend/Chapter8/vec3.h
    src/InOneWeekend/Chapter8/color.h
    src/InOneWeekend/Chapter8/ray.h
    src/InOneWeekend/Chapter8/rtweekend.h
    src/InOneWeekend/Chapter8/sphere.h
    src/InOneWeekend/Chapter8/hittable.h
    src/InOneWeekend/Chapter8/interval.h
    src/InOneWeekend/Chapter8/hittable_list.h
    src/InOneWeekend/Chapter8/rt1-chapter8.cpp
)

set ( SOURCE_FILES91
    src/InOneWeekend/Chapter9.1/vec3.h
    src/InOneWeekend/Chapter9.1/color.h
    src/InOneWeekend/Chapter9.1/ray.h
    src/InOneWeekend/Chapter9.1/rtweekend.h
    src/InOneWeekend/Chapter9.1/sphere.h
    src/InOneWeekend/Chapter9.1/hittable.h
    src/InOneWeekend/Chapter9.1/interval.h
    src/InOneWeekend/Chapter9.1/hittable_list.h
    src/InOneWeekend/Chapter9.1/rt1-chapter9.1.cpp
)

set ( SOURCE_FILES92
    src/InOneWeekend/Chapter9.2/vec3.h
    src/InOneWeekend/Chapter9.2/color.h
    src/InOneWeekend/Chapter9.2/ray.h
    src/InOneWeekend/Chapter9.2/rtweekend.h
    src/InOneWeekend/Chapter9.2/sphere.h
    src/InOneWeekend/Chapter9.2/hittable.h
    src/InOneWeekend/Chapter9.2/interval.h
    src/InOneWeekend/Chapter9.2/hittable_list.h
    src/InOneWeekend/Chapter9.2/rt1-chapter9.2.cpp
)

set ( SOURCE_FILES93
    src/InOneWeekend/Chapter9.3/vec3.h
    src/InOneWeekend/Chapter9.3/color.h
    src/InOneWeekend/Chapter9.3/ray.h
    src/InOneWeekend/Chapter9.3/rtweekend.h
    src/InOneWeekend/Chapter9.3/sphere.h
    src/InOneWeekend/Chapter9.3/hittable.h
    src/InOneWeekend/Chapter9.3/interval.h
    src/InOneWeekend/Chapter9.3/hittable_list.h
    src/InOneWeekend/Chapter9.3/rt1-chapter9.3.cpp
)

set ( SOURCE_FILES94
    src/InOneWeekend/Chapter9.4/vec3.h
    src/InOneWeekend/Chapter9.4/color.h
    src/InOneWeekend/Chapter9.4/ray.h
    src/InOneWeekend/Chapter9.4/rtweekend.h
    src/InOneWeekend/Chapter9.4/sphere.h
    src/InOneWeekend/Chapter9.4/hittable.h
    src/InOneWeekend/Chapter9.4/interval.h
    src/InOneWeekend/Chapter9.4/hittable_list.h
    src/InOneWeekend/Chapter9.4/rt1-chapter9.4.cpp
)

set ( SOURCE_FILES95
    src/InOneWeekend/Chapter9.5/vec3.h
    src/InOneWeekend/Chapter9.5/color.h
    src/InOneWeekend/Chapter9.5/ray.h
    src/InOneWeekend/Chapter9.5/rtweekend.h
    src/InOneWeekend/Chapter9.5/sphere.h
    src/InOneWeekend/Chapter9.5/hittable.h
    src/InOneWeekend/Chapter9.5/interval.h
    src/InOneWeekend/Chapter9.5/hittable_list.h
    src/InOneWeekend/Chapter9.5/rt1-chapter9.5.cpp
)

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID})

# add executable
add_executable( chapter2.2.exe ${SOURCE_FILES22} )
add_executable( chapter2.3.exe ${SOURCE_FILES23} )
add_executable( chapter3.1.exe ${SOURCE_FILES31} )
add_executable( chapter4.2.exe ${SOURCE_FILES42} )
add_executable( chapter5.2.exe ${SOURCE_FILES52} )
add_executable( chapter6.2.exe ${SOURCE_FILES62} )
add_executable( chapter6.8.exe ${SOURCE_FILES68} )
add_executable( chapter7.exe ${SOURCE_FILES7} )
add_executable( chapter8.exe ${SOURCE_FILES8} )
add_executable( chapter9.1.exe ${SOURCE_FILES91} )
add_executable( chapter9.2.exe ${SOURCE_FILES92} )
add_executable( chapter9.3.exe ${SOURCE_FILES93} )
add_executable( chapter9.4.exe ${SOURCE_FILES94} )
add_executable( chapter9.5.exe ${SOURCE_FILES95} )