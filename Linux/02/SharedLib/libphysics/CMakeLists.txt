cmake_minimum_required(VERSION 3.30)
project(libphysics)

add_library(physics SHARED physics.cpp)

target_include_directories(physics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})