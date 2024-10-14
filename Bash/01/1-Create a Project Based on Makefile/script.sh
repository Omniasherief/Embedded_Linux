#!/bin/bash
echo "Enter Project name : "
read project_name
mkdir -p "$project_name"/{src,include,build}

touch "$project_name/Makefile"
cat << EOF > "$project_name/Makefile"
CC=g++
CFLAGS= -Iinclude -wall
all :build/main 
build/main: src/main.cpp
\t\$(CC) \$(CFLAGS) src/main.cpp -o build/main

clean:
\trm -rf build/*
EOF
#CFLAGS = -Iinclude -Wall:

   # -Iinclude: Tells the compiler to look for header files in the include directory.
    #-Wall: Enables all compiler warnings.
    #all: The default target. It depends on build/main, which is the compiled binary.
    # \t: Adds a tab (required by make for commands).
    # -o build/main: Specifies the output file as build/main.
cat <<EOF > "$project_name/src/main.cpp"
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOF
#clean: A utility target to remove all files in the build directory.
#rm -rf build/*: Forcefully deletes everything in the build folder.

echo "Project '$project_name' created successfully!"