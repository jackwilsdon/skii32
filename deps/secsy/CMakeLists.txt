cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)
include(GenerateExportHeader)

require_cxx11()

set(secsy_SOURCES
    src
)

set(secsy_INCLUDES
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Iterate each include file and add it to secsy_INCLUDE_FILES
foreach(SOURCE_PATH ${secsy_SOURCES})
    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_PATH}/*)

    list(APPEND secsy_SOURCE_FILES ${SOURCE_FILES})
endforeach(SOURCE_PATH)


# Iterate each include file and add it to secsy_INCLUDE_FILES
foreach(INCLUDE_PATH ${secsy_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND secsy_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(secsy STATIC ${secsy_SOURCES} ${secsy_SOURCE_FILES} ${secsy_INCLUDES} ${secsy_INCLUDE_FILES})

# Generate export headers
generate_export_header(secsy EXPORT_FILE_NAME include/secsy/export.h)

# Add include directories to library
target_include_directories(secsy PUBLIC ${secsy_INCLUDES})
