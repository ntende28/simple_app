# simple_app
Working on a simple CLI app to carry out create, read, update & delete using students case study


For build system;
1. Open the project folder, and create a build folder
    mkdir build

2. Create build system for cmake (in root directory)
    #Linux 
    Run command in build folder *cmake -S ../ -B .* 
    
    #Windows
    set system environment variables;
        CMAKE_C_COMPILE     | path to compiler e.g. C:\TDM-GCC-64\bin\gcc.exe
        CMAKE_CXX_COMPILER  | path to compiler e.g. C:\TDM-GCC-64\bin\g++.exe
    *cmake -G "MinGW Makefiles" -B build*


3. Build application
    *cmake --build build*

4. Whenever you update the source files and headers, ensure to do steps 2 and 3
