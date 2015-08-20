cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

include(CXX11)

require_cxx11()

set(logger_SOURCES
    src/destinations/console_destination.cc
    src/log_destination.cc
    src/log_level.cc
    src/logger.cc
)

set(logger_INCLUDES
    include
)

# Iterate each include file and add it to logger_INCLUDE_FILES
foreach(INCLUDE_PATH ${logger_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND logger_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(logger SHARED ${logger_SOURCES} ${logger_INCLUDE_FILES})

# Add include directories to library
target_include_directories(logger PUBLIC ${logger_INCLUDES})
