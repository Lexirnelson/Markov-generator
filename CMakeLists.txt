cmake_minimum_required(VERSION 3.15)
project(Project5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project5 main.cpp brute_model.cpp brute_model.h map_model.cpp map_model.h markov.cpp markov.h model.h word_model.cpp word_model.h)