cmake_minimum_required(VERSION 3.14)
project(project_name)
set(CMAKE_CXX_STANDARD 17)

add_library(answer answer.cpp) # our own library with both .h and .cpp files

add_executable(project_name main.cpp) # our main executable file
target_link_libraries(project_name answer) # link executable with answer library

add_executable(test CatchMain.cpp test_answer.cpp) # make an executable for running tests
target_link_libraries(test answer) # link test-executable with answer library
