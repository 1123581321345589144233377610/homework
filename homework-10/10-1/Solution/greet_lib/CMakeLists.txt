cmake_minimum_required(VERSION 3.20)

project(greet_lib)

set(lib_files greet_lib.cpp)

add_executable(greet_lib ${lib_files})

add_library(greet_lib STATIC ${lib_files})