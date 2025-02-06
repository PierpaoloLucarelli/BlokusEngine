cmake_minimum_required(VERSION 3.16)
project(BlokusEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")

add_subdirectory(src/blokusboardlib)

add_executable(BlokusEngine
    src/main.cpp
    src/minimax.cpp
)

target_link_libraries(BlokusEngine PRIVATE blokusboardlib)
find_package(Curses REQUIRED)
target_link_libraries(BlokusEngine PRIVATE ${CURSES_LIBRARIES})

target_include_directories(BlokusEngine PRIVATE include)
