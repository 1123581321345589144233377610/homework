cmake_minimum_required(VERSION 3.20)

project(my_project)

include_directories(greet_lib)

add_executable(my_project main.cpp)

add_subdirectory(greet_lib)

target_link_libraries(my_project greet_lib)

