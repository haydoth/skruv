@echo off

set LIBS= C:/storage/engine_dependencies/lib
set INCLUDES= "C:/storage/engine_dependencies/include"
set LINKER_FLAGS= user32.lib gdi32.lib kernel32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib opengl32.lib glfw3.lib
set COMPILER_OPTIONS= /std:c++20 /Fe:./build/main.exe /Fo:./build/ /EHsc

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

call cl %COMPILER_OPTIONS% src/main.cpp vendor/glad.c /I %INCLUDES% /link %LINKER_FLAGS% /libpath:C:/storage/engine_dependencies/lib

"./build/main.exe"