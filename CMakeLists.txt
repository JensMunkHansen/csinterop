cmake_minimum_required(VERSION 3.18)

# TODO: Figure out how to reference Interop from CSharp
project(CSINTEROP
  VERSION 1.0.0
  LANGUAGES CXX # CSharp
)

# TODO: Add CSHARP

set(CSINTEROP_MAJOR_VERSION 1)
set(CSINTEROP_MINOR_VERSION 0)
set(CSINTEROP_PATCH_VERSION 0)
set(CSINTEROP_SHORT_VERSION "${CSINTEROP_MAJOR_VERSION}.${CSINTEROP_MINOR_VERSION}")
set(CSINTEROP_VERSION "${CSINTEROP_SHORT_VERSION}.${CSINTEROP_PATCH_VERSION}")

set(LIB_TYPE STATIC)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if (BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif()

# HACK: Copy output of interop into the CSharp project
set(NET_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dotnet")

add_subdirectory(native)

add_subdirectory(interop)

# TODO: Figure out how to reference Interop from CSharp
# add_subdirectory(dotnet)
