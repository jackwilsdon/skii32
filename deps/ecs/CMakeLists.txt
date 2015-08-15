cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)

require_cxx11()

set(ecs_SOURCES)

set(ecs_INCLUDES
    include
)

# Iterate each include file and add it to ecs_INCLUDE_FILES
foreach(INCLUDE_PATH ${ecs_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND ecs_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(ecs INTERFACE)

# Add include directories to library
target_include_directories(ecs INTERFACE ${ecs_INCLUDES})
