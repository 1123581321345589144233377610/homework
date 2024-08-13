cmake_minimum_required(VERSION 3.20)

project(leave_lib)

set(dll_files leave_lib.cpp)

add_library(leave_lib SHARED ${dll_files})
