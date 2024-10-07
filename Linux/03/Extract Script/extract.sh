#!/bin/bash

# Function to extract various archive formats
extract () {
    if [ -f "$1" ]; then  # Check if the provided argument is a valid file
        echo "Extracting file: $1"  # Debug output to see which file is being processed
        case "$1" in
            *.tar.bz2)  # For .tar.bz2 files
                echo "Extracting tar.bz2..."
                tar xvjf "$1"
                ;;
            *.tar.gz)  # For .tar.gz files
                echo "Extracting tar.gz..."
                tar xvzf "$1"
                ;;
            *.tar.xz)  # For .tar.xz files
                echo "Extracting tar.xz..."
                tar xvJf "$1"
                ;;
            *.bz2)  # For .bz2 files
                echo "Extracting bz2..."
                bunzip2 "$1"
                ;;
            *.rar)  # For .rar files
                echo "Extracting rar..."
                rar x "$1"
                ;;
            *.gz)  # For .gz files
                echo "Extracting gz..."
                gunzip "$1"
                ;;
            *.tar)  # For .tar files
                echo "Extracting tar..."
                tar xvf "$1"
                ;;
            *.tbz2)  # For .tbz2 files
                echo "Extracting tbz2..."
                tar xvjf "$1"
                ;;
            *.tgz)  # For .tgz files
                echo "Extracting tgz..."
                tar xvzf "$1"
                ;;
            *.zip)  # For .zip files
                echo "Extracting zip..."
                dir=$(echo "$1" | sed 's/\(.*\)\.zip/\1/')  # Create a directory based on the zip file name
                mkdir -p "$dir"
                unzip "$1" -d "$dir"  # Extract the zip contents into the directory
                ;;
            *.Z)  # For .Z files
                echo "Extracting Z..."
                uncompress "$1"
                ;;
            *.7z)  # For .7z files
                echo "Extracting 7z..."
                7z x "$1"
                ;;
            *)
                echo "Don't know how to extract '$1'"  # If the file format is not recognized
                ;;
        esac
    else
        echo "$1 is not a valid file!"  # If the provided argument is not a file
    fi
}

# Call the extract function with the first argument passed to the script
extract "$1"

