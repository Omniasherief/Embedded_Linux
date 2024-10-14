#!/bin/bash

# Define options
options="C++
Python
Linux Commands
Bash"

# Use fzf to select an option
choice=$(echo -e "$options" | fzf --header="Choose a programming language or command:")

# Handle the selected choice
case $choice in
  "C++")
    echo -e '#include <iostream>\nint main(){ std::cout << "Hello"; return 0; }' >> main.cpp
    ;;
  "Python")
    echo 'print("Hello, World!")' >> main.py
    ;;
  "Linux Commands")
    echo -e "ls: list files\npwd: print directory" 
    ;;
  "Bash")
    echo -e '#!/bin/bash\necho "Hello, World!"' >> main.sh
    ;;
  *)
    echo "Invalid choice!"
    ;;
esac