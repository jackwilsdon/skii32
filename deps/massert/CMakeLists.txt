cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

include(GenerateExportHeader)

set(massert_SOURCES
    src/massert.cc
)

set(massert_INCLUDES
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Iterate each include file and add it to massert_INCLUDE_FILES
foreach(INCLUDE_PATH ${massert_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND massert_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(massert SHARED ${massert_SOURCES} ${massert_INCLUDE_FILES})

# Generate export headers
generate_export_header(massert EXPORT_FILE_NAME include/massert/export.h)

# Add include directories to library
target_include_directories(massert PUBLIC ${massert_INCLUDES})
