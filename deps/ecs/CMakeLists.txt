cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)
include(GenerateExportHeader)

require_cxx11()

set(ecs_SOURCES
    src
)

set(ecs_INCLUDES
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Iterate each include file and add it to ecs_INCLUDE_FILES
foreach(SOURCE_PATH ${ecs_SOURCES})
    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_PATH}/*)

    list(APPEND ecs_SOURCE_FILES ${SOURCE_FILES})
endforeach(SOURCE_PATH)


# Iterate each include file and add it to ecs_INCLUDE_FILES
foreach(INCLUDE_PATH ${ecs_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND ecs_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(ecs STATIC ${ecs_SOURCE_FILES} ${ecs_INCLUDE_FILES})

# Generate export headers
generate_export_header(ecs EXPORT_FILE_NAME include/ecs/export.h)

# Add include directories to library
target_include_directories(ecs PUBLIC ${ecs_INCLUDES})
