cmake_minimum_required(VERSION 3.14)
project(u35_2)

set(CMAKE_CXX_STANDARD 17)

add_library(options options.cpp) #add our options library

add_executable(u35_2 main.cpp) # add an executable program

target_link_libraries(u35_2 options) #link executable with our options library