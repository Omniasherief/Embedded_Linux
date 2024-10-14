CC=g++
CFLAGS= -Iinclude -wall
all :build/main 
build/main: src/main.cpp
\t$(CC) $(CFLAGS) src/main.cpp -o build/main

clean:
\trm -rf build/*
