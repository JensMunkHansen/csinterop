# Consider/check Class Library, netstandard2.0, Embed manifest with default settings

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

execute_process(
  COMMAND swig -csharp -c++ -namespace ${GLOBAL_NAMESPACE} -I${PROJECT_SOURCE_DIR}/native -I${PROJECT_BINARY_DIR}/native -outcurrentdir ${CMAKE_CURRENT_SOURCE_DIR}/interop.i
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

file(GLOB OUT_SRC
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_BINARY_DIR}/*.cs"
)

set_property(SOURCE interop.i PROPERTY CPLUSPLUS ON)

set_property(SOURCE interop.i
  PROPERTY
  USE_TARGET_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/native;${PROJECT_BINARY_DIR}/native"
)
set_property(SOURCE interop.i
  PROPERTY
  SWIG_FLAGS "-namespace" ${GLOBAL_NAMESPACE})

if (HACK)
  swig_add_library(MyLibraryInterop
    TYPE SHARED
    LANGUAGE CSharp
    SOURCES interop.i ${OUT_SRC}
    OUTPUT_DIR ${NET_PROJECT_DIR} # WORKS
    OUTFILE_DIR ${NET_PROJECT_DIR}) # WORKS
else()
  swig_add_library(MyLibraryInterop
    TYPE SHARED
    LANGUAGE CSharp
    SOURCES interop.i ${OUT_SRC}
    OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}
    OUTFILE_DIR ${CMAKE_CURRENT_BINARY_DIR})
endif()


swig_link_libraries(MyLibraryInterop PUBLIC MyLibrary)

add_library(mylibs::MyLibraryInterop ALIAS MyLibraryInterop)
set_property(TARGET MyLibraryInterop PROPERTY DOTNET_TARGET_FRAMEWORK_VERSION ${CSINTEROP_DOTNET_TARGET_FRAMEWORK_VERSION})
# set_property(TARGET MyLibraryInterop PROPERTY VS_DOTNET_REFERENCES "CSharp")

if (HACK)
  set(NETDIR "net6.0")

  # for copying .dll to .Net project dir dir
  set_target_properties( MyLibraryInterop
    PROPERTIES
    
    # These copy .dll on Windows 
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${NET_PROJECT_DIR}/bin/Release/${NETDIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${NET_PROJECT_DIR}/bin/Debug/${NETDIR}
  
    # This copies .so on Linux to .Net project directory
    LIBRARY_OUTPUT_DIRECTORY ${NET_PROJECT_DIR}
  
    # Set address of C++ headers (if any)
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
  )
else()
  set_target_properties( MyLibraryInterop
    PROPERTIES
  
    # These copy .dll on Windows to .Net project directory
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/Release
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/Debug
  
    # This copies .so on Linux to .Net project directory
    LIBRARY_OUTPUT_DIRECTORY ${NET_PROJECT_DIR}
  
    # Set address of C++ headers (if any)
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()

# Utility function for dumping variables
function(dump_cmake_variables)
  get_cmake_property(_variableNames VARIABLES)
  list (SORT _variableNames)
  foreach (_variableName ${_variableNames})
    if (ARGV0)
      unset(MATCHED)
      string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
      if (NOT MATCHED)
        continue()
      endif()
    endif()
    message(STATUS "${_variableName}=${${_variableName}}")
  endforeach()
endfunction()

# dump_cmake_variables()
