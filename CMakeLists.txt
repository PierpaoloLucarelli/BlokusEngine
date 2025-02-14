cmake_minimum_required(VERSION 3.16)
project(BlokusEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(pybind11 REQUIRED)

# Set Debug as the default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Enable debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "-g")

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")

add_subdirectory(src/blokusboardlib)

add_executable(BlokusEngine
    src/main.cpp
    src/minimax.cpp
)

target_link_libraries(BlokusEngine PRIVATE blokusboardlib)

add_library(pyblokus  MODULE
    src/pyblokus.cpp
)

target_link_libraries(pyblokus  PRIVATE pybind11::module blokusboardlib)

set_target_properties(pyblokus PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_NAME "pyblokus"
)

target_include_directories(BlokusEngine PRIVATE include)
