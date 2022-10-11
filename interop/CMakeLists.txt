find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
# set(SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE) # Why link libraries does not work

set_property(SOURCE interop.i PROPERTY CPLUSPLUS ON)

set_property(SOURCE interop.i
  PROPERTY
  USE_TARGET_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/native;${PROJECT_BINARY_DIR}/native"
)
set_property(SOURCE interop.i
  PROPERTY
  SWIG_FLAGS "-namespace" "MyLibraryInterop")
  
swig_add_library(MyLibraryInterop
  TYPE SHARED
  LANGUAGE CSharp
  SOURCES interop.i
  OUTPUT_DIR ${NET_PROJECT_DIR}
  OUTFILE_DIR ${NET_PROJECT_DIR})

swig_link_libraries(MyLibraryInterop PUBLIC MyLibrary)

# for copying .dll to .Net project dir dir
set_target_properties( MyLibraryInterop
  PROPERTIES

  # These copy .dll on Windows to .Net project directory
  RUNTIME_OUTPUT_DIRECTORY_RELEASE ${NET_PROJECT_DIR}
  RUNTIME_OUTPUT_DIRECTORY_DEBUG ${NET_PROJECT_DIR}

  #RUNTIME_OUTPUT_DIRECTORY_RELEASE $<TARGET_FILE_DIR:Main>
  #RUNTIME_OUTPUT_DIRECTORY_DEBUG $<TARGET_FILE_DIR:Main>

  # This copies .so on Linux to .Net project directory
  LIBRARY_OUTPUT_DIRECTORY ${NET_PROJECT_DIR}

  # Set address of C++ headers (if any)
  INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)
