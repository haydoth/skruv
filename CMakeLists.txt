cmake_minimum_required(VERSION 3.5)

include(CMakePrintHelpers)

project(skruv LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src/)
include_directories(${CMAKE_SOURCE_DIR}/vendor/)

set(skruv_SRC

src/main.cpp

src/core/State.cpp
src/core/WindowModule.cpp

src/core/scene/SceneModule.cpp
src/core/scene/Scene.cpp
src/core/scene/Entity.cpp

src/core/render/RenderModule.cpp
src/core/render/Shader.cpp

)

set(skruv_VENDOR_SRC
vendor/glad/glad.c
)

LINK_DIRECTORIES(vendor/)
LINK_DIRECTORIES(vendor/glfw)

add_executable(skruv ${skruv_SRC} ${skruv_VENDOR_SRC})
TARGET_LINK_LIBRARIES(skruv opengl32.lib libglfw3dll.a gdi32.lib)
