cmake_minimum_required(VERSION 3.30)
project(libgeo)


add_library(geometry SHARED geometry.cpp)


target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
