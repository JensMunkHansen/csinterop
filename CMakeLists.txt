cmake_minimum_required(VERSION 3.18)

# TODO: Figure out how to reference Interop from CSharp
project(CSINTEROP
  VERSION 1.0.0
  LANGUAGES CXX CSharp
)

set(CSINTEROP_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")

set(CSINTEROP_MAJOR_VERSION 1)
set(CSINTEROP_MINOR_VERSION 0)
set(CSINTEROP_PATCH_VERSION 0)
set(CSINTEROP_SHORT_VERSION "${CSINTEROP_MAJOR_VERSION}.${CSINTEROP_MINOR_VERSION}")
set(CSINTEROP_VERSION "${CSINTEROP_SHORT_VERSION}.${CSINTEROP_PATCH_VERSION}")

set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

set(LIB_TYPE STATIC)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if (BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif()


set(CMAKE_CSharp_FLAGS "${CMAKE_CSharp_FLAGS} /langversion:6")

# HACK: Copy output of interop into the CSharp project
set(NET_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dotnet")

set(GLOBAL_NAMESPACE SampleInterop)

set(DOTNET_TARGET_FRAMEWORK ${CSINTEROP_DOTNET_TARGET_FRAMEWORK_VERSION})

set(HACK 1)

add_subdirectory(native)

add_subdirectory(interop)

if (NOT HACK)
  # TODO: Figure out how to reference Interop from CSharp
  add_subdirectory(dotnet)
endif()
