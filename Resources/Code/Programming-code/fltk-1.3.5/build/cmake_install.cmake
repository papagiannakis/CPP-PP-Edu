# Install script for directory: /Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/FL" USE_SOURCE_PERMISSIONS REGEX "/\\.svn$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/FL" USE_SOURCE_PERMISSIONS)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake/FLTK-Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake/FLTK-Targets.cmake"
         "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/CMakeFiles/Export/af386ca283b4e6ea66f3bc432bf350b6/FLTK-Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake/FLTK-Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake/FLTK-Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake" TYPE FILE FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/CMakeFiles/Export/af386ca283b4e6ea66f3bc432bf350b6/FLTK-Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake" TYPE FILE FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/CMakeFiles/Export/af386ca283b4e6ea66f3bc432bf350b6/FLTK-Targets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake" TYPE FILE FILES
    "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/etc/FLTKConfig.cmake"
    "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/CMake/FLTK-Functions.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FLTK/.framework/Resources/CMake" TYPE FILE FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/etc/UseFLTK.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/bin/fltk-config")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE RENAME "fluid.1" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/fluid.man")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE RENAME "fltk-config.1" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/fltk-config.man")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man3" TYPE FILE RENAME "fltk.3" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/fltk.man")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man6" TYPE FILE RENAME "blocks.6" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/blocks.man")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man6" TYPE FILE RENAME "checkers.6" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/checkers.man")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man6" TYPE FILE RENAME "sudoku.6" FILES "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/documentation/src/sudoku.man")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/fluid/cmake_install.cmake")
  include("/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/src/cmake_install.cmake")
  include("/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/papagian/GPcode/Courseware/HY150/_Stroustrup/src/Programming-code/fltk-1.3.5/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
