cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

project(skii32)

include(CXX11)

require_cxx11()

add_subdirectory(deps)

set(skii32_SOURCES
    skii32/skii32.cc
)

add_executable(skii32 ${skii32_SOURCES})
target_link_libraries(skii32 logger)
