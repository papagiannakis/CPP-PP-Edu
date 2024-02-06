project(Chapter-GUI-assignment-2023)

cmake_minimum_required(VERSION 3.1.4)

#add_dependencies()
add_executable(Ass3 Ass3.cpp Player.cpp)


message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "LINK_OPTIONS: ${LINK_OPTIONS}")

# ------------------------------------------------------------------------------------------
# LINK Chapter.12.3. with GUI & FLTK
target_include_directories(Ass3 PUBLIC ${CMAKE_SOURCE_DIR}/fltk-1.3.5 ${CMAKE_BINARY_DIR}/fltk-1.3.5 ${CMAKE_SOURCE_DIR}/GUI ../GUI ./)
target_link_directories(Ass3 PUBLIC ${CMAKE_BINARY_DIR}/fltk-1.3.5/lib/Debug)

# Not necessary on windows
# target_link_options(chapter.12.3 PUBLIC -lfltk -lm -lpthread -ldl -lfltk_images -lstdc++ -lfltk_jpeg)
# target_compile_options(chapter.12.3 PUBLIC "-D_THREAD_SAFE -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE")
# target_link_directories(chapter.12.3 PUBLIC /usr/local/lib)

target_link_libraries(Ass3 PUBLIC bookgui fltk fltk_images)
if (APPLE)
    target_link_libraries(Ass3 PUBLIC "-framework Cocoa")
endif()
# ------------------------------------------------------------------------------------------

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_LINK_LIBRARY_FLAGS: ${CMAKE_CXX_LINK_LIBRARY_FLAGS}")