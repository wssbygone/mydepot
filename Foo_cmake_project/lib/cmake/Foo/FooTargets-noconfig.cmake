#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Foo::Foo" for configuration ""
set_property(TARGET Foo::Foo APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Foo::Foo PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libFoo.so"
  IMPORTED_SONAME_NOCONFIG "libFoo.so"
  )

list(APPEND _cmake_import_check_targets Foo::Foo )
list(APPEND _cmake_import_check_files_for_Foo::Foo "${_IMPORT_PREFIX}/lib/libFoo.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
