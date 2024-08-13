cmake_minimum_required(VERSION 3.20)

project(greet_lib)

set(lib_files greet_lib.cpp)

add_library(greet_lib STATIC ${lib_files})