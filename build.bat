
set LIBS= C:/storage/engine_dependencies/lib
set INCLUDES= C:/storage/engine_dependencies/include
set LINKER_FLAGS= -lopengl32 -lglfw3 -lgdi32
set COMPILER_OPTIONS= --std=c++20 -fpermissive

set VENDOR= vendor/glad.c

set SRC= src/core/scene/Entity.cpp src/core/scene/Scene.cpp src/core/scene/SceneModule.cpp src/core/WindowModule.cpp src/core/State.cpp src/main.cpp

call g++ -o build/main.exe -g %SRC% %VENDOR% %COMPILER_OPTIONS% -IC:/storage/engine_dependencies/include -LC:/storage/engine_dependencies/lib %LINKER_FLAGS%