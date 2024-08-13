cmake_minimum_required(VERSION 3.20)

project(my_lib)

set(dll_files my_lib.cpp)
add_library(my_lib SHARED ${dll_files})