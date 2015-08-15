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
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add source to library
add_library(logger SHARED ${logger_SOURCES})

# Add include directories to library
target_include_directories(logger PUBLIC ${logger_INCLUDES})
