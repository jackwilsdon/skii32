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
    src
)

set(skii32_INCLUDES
    include
)

# Iterate each include file and add it to skii32_SOURCE_FILES
foreach(SOURCE_PATH ${skii32_SOURCES})
    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_PATH}/*)

    list(APPEND skii32_SOURCE_FILES ${SOURCE_FILES})
endforeach(SOURCE_PATH)

# Iterate each include file and add it to logger_INCLUDE_FILES
foreach(INCLUDE_PATH ${logger_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND logger_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to executable
add_executable(skii32 ${skii32_SOURCES} ${skii32_SOURCE_FILES} ${skii32_INCLUDE_FILES})

# Add dependencies
target_link_libraries(skii32 secsy)
