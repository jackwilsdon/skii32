cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)
include(GenerateExportHeader)

require_cxx11()

set(logger_SOURCES
    src
)

set(logger_INCLUDES
    include
)

# Iterate each include file and add it to logger_INCLUDE_FILES
foreach(SOURCE_PATH ${logger_SOURCES})
    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_PATH}/*)

    list(APPEND logger_SOURCE_FILES ${SOURCE_FILES})
endforeach(SOURCE_PATH)


# Iterate each include file and add it to logger_INCLUDE_FILES
foreach(INCLUDE_PATH ${logger_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND logger_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(logger STATIC ${logger_SOURCE_FILES} ${logger_INCLUDE_FILES})

# Generate export headers
generate_export_header(logger EXPORT_FILE_NAME include/logger/export.h)

# Add include directories to library
target_include_directories(logger PUBLIC ${logger_INCLUDES})
