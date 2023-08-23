call cd build
call cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G"MinGW Makefiles" ..
call mingw32-make