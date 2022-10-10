include(GenerateExportHeader)

add_library(MyLibrary ${LIB_TYPE} mylib.cpp)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

generate_export_header(MyLibrary)

target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
