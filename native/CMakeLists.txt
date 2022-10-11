include(GenerateExportHeader)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

set(MYLIBRARY_PUBLIC_HEADERS
  "${CMAKE_CURRENT_BINARY_DIR}/mylibrary_export.h"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  mylib.h
)

set(MYLIBRARY_SOURCES
  mylib.cpp
)

add_library(MyLibrary ${LIB_TYPE} ${MYLIBRARY_SOURCES} ${MYLIBRARY_PUBLIC_HEADERS})

generate_export_header(MyLibrary)

target_include_directories(MyLibrary
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(MyLibrary
    PROPERTIES
    # Copies .dll to .Net project directory
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${NET_PROJECT_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${NET_PROJECT_DIR}

    # This copies .so on Linux to .Net project directory
    LIBRARY_OUTPUT_DIRECTORY ${NET_PROJECT_DIR}
)
