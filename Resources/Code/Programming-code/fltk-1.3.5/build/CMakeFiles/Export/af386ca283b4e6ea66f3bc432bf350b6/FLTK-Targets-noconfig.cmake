#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fluid" for configuration ""
set_property(TARGET fluid APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(fluid PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/fluid.app/Contents/MacOS/fluid"
  )

list(APPEND _cmake_import_check_targets fluid )
list(APPEND _cmake_import_check_files_for_fluid "${_IMPORT_PREFIX}/bin/fluid.app/Contents/MacOS/fluid" )

# Import target "fltk" for configuration ""
set_property(TARGET fltk APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(fltk PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libdl.tbd"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfltk.a"
  )

list(APPEND _cmake_import_check_targets fltk )
list(APPEND _cmake_import_check_files_for_fltk "${_IMPORT_PREFIX}/lib/libfltk.a" )

# Import target "fltk_forms" for configuration ""
set_property(TARGET fltk_forms APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(fltk_forms PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "fltk"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfltk_forms.a"
  )

list(APPEND _cmake_import_check_targets fltk_forms )
list(APPEND _cmake_import_check_files_for_fltk_forms "${_IMPORT_PREFIX}/lib/libfltk_forms.a" )

# Import target "fltk_images" for configuration ""
set_property(TARGET fltk_images APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(fltk_images PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "fltk;/opt/homebrew/lib/libjpeg.dylib;/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libz.tbd;/opt/homebrew/lib/libpng.dylib;/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libz.tbd"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfltk_images.a"
  )

list(APPEND _cmake_import_check_targets fltk_images )
list(APPEND _cmake_import_check_files_for_fltk_images "${_IMPORT_PREFIX}/lib/libfltk_images.a" )

# Import target "fltk_gl" for configuration ""
set_property(TARGET fltk_gl APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(fltk_gl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "fltk;/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/System/Library/Frameworks/OpenGL.framework;/Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/System/Library/Frameworks/OpenGL.framework"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libfltk_gl.a"
  )

list(APPEND _cmake_import_check_targets fltk_gl )
list(APPEND _cmake_import_check_files_for_fltk_gl "${_IMPORT_PREFIX}/lib/libfltk_gl.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
