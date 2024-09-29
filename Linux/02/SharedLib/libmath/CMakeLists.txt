cmake_minimum_required(VERSION 3.30)
project(libmath)

#create shared lib from math.cpp
add_library(math SHARED math.cpp)

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
