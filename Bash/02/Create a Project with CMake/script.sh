#!/bin/bash

# Check if a project name was provided as an argument
if [ -z "$1" ]; then
    echo "Usage: ./script.sh <project_name>"
    exit 1
fi

project_name="$1"
project_dir="./$project_name"

# Create the project directory
mkdir -p "$project_dir"
cd "$project_dir" || exit

# Create CMakeLists.txt file
cat << EOL >CMakeLists.txt
cmake_minimum_required(VERSION 3.30)
project($project_name)
set(CMAKE_CXX_STANDARD 17)
add_executable($project_name main.cpp)
EOL

# Create main.cpp file
cat <<EOL >main.cpp
#include <iostream>

int main() {
    std::cout << "Hello, $project_name!" << std::endl;
    return 0;
}
EOL

# Create a build directory
mkdir build

# Instructions for building the project
echo "C++ project '$project_name' has been created."
echo "To build the project, run the following commands:"
echo "cd $project_name/build"
echo "cmake .."
echo "make"










