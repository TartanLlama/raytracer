cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(raytrace)
add_executable(raytrace src/raytrace.cpp)
target_include_directories(raytrace PUBLIC include ext)