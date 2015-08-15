cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(platform_INCLUDES
    include
)

# Iterate each include file and add it to platform_INCLUDE_FILES
foreach(INCLUDE_PATH ${platform_INCLUDES})
    file(GLOB_RECURSE INCLUDE_FILES ${INCLUDE_PATH}/*)

    list(APPEND platform_INCLUDE_FILES ${INCLUDE_FILES})
endforeach(INCLUDE_PATH)

# Add source to library
add_library(platform INTERFACE)

# Add include directories to library
target_include_directories(platform INTERFACE ${platform_INCLUDES})
