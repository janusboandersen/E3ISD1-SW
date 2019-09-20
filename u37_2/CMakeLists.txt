cmake_minimum_required(VERSION 3.14)
project(u37_2)

set(CMAKE_CXX_STANDARD 17)
add_library(Options Options.cpp)

add_executable(u37_2 main.cpp)
target_link_libraries(u37_2 Options)