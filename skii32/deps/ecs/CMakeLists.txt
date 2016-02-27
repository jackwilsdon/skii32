cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)
include(GenerateExportHeader)

require_cxx11()

set(ecs_SOURCES
    src/component_set.cc
    src/entity.cc
    src/type_identifier.cc
    src/world.cc
)

set(ecs_INCLUDES
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Iterate each include file and add it to ecs_INCLUDE_FILES
foreach(INCLUDE_PATH ${ecs_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND ecs_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(ecs SHARED ${ecs_SOURCES} ${ecs_INCLUDE_FILES})

# Generate export headers
generate_export_header(ecs EXPORT_FILE_NAME include/ecs/export.h)

# Add include directories to library
target_include_directories(ecs PUBLIC ${ecs_INCLUDES})

# Add dependencies
target_link_libraries(ecs massert)
