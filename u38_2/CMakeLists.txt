cmake_minimum_required(VERSION 3.14)
project(u38_2)

set(CMAKE_CXX_STANDARD 17)
add_library(Options Options.cpp)
add_library(OptionsChars OptionsChars.cpp)
add_library(OptionsKeywords OptionsKeywords.cpp)

add_executable(u38_2 main.cpp)
target_link_libraries(u38_2 Options OptionsChars OptionsKeywords)