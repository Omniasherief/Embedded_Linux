#!/bin/bash

# Prompt for user inputs
read -p "Please enter your name: " name
echo "Hello  ${name}"

read -p "Please enter your class name: " classname
read -p "Please enter your namespace: " namespace

# Ask for the directory path
read -p "Enter the directory path where you want to save the files: " path

# Create the directory if it doesn't exist
if [ ! -d "$path" ]; then
    echo "Directory does not exist. Creating it..."
    mkdir -p "$path" || { echo "Failed to create directory."; exit 1; }
fi

# Generate the header file content
header_content="
#pragma once
/**********************************************
// Copyright ${name}
***********************************************/

/*
Author: ${name}
Date: $(date)
Brief: Header file for ${classname} class
*/

namespace ${namespace} {
class ${classname} {
public:
    ${classname}();
    ~${classname}();
private:
};
}
"

# Create the .hpp file
echo "$header_content" > "${path}/${classname}.hpp"
echo "\"${classname}.hpp\" has been created in $path."

# Ask user if they want to generate the .cpp file
read -p "Do you want the cpp file (Y/N)? " answer

if [[ ${answer^^} == "Y" ]]; then
    # Generate the cpp file content
    cpp_content="
/**********************************************
// Copyright ${name}
***********************************************/

/*
Author: ${name}
Date: $(date)
Brief: Implementation file for ${classname} class
*/

#include \"${classname}.hpp\"

namespace ${namespace} {
${classname}::${classname}() {}
${classname}::~${classname}() {}
}
"
    # Create the .cpp file
    echo "$cpp_content" > "${path}/${classname}.cpp"
    echo "\"${classname}.cpp\" has been created in $path."
else
    echo "No cpp file created."
fi
