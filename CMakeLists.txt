cmake_minimum_required(VERSION 3.2)

include(CMakePrintHelpers)

project(skruv LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE skruv_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE skruv_VENDOR_SOURCES_C CONFIGURE_DEPENDS "vendor/*.c")
file (GLOB_RECURSE skruv_VENDOR_SOURCES CONFIGURE_DEPENDS "vendor/*.cpp")

INCLUDE_DIRECTORIES(C:/storage/engine_dependencies/include)
INCLUDE_DIRECTORIES(vendor/)
LINK_DIRECTORIES(C:/storage/engine_dependencies/lib)
LINK_DIRECTORIES(vendor/)

cmake_print_variables(skruv_VENDOR_SOURCES_C)

add_executable(skruv ${skruv_SOURCES} ${skruv_VENDOR_SOURCES_C} ${skruv_VENDOR_SOURCES})
TARGET_LINK_LIBRARIES(skruv opengl32.lib glfw3.lib gdi32.lib)
