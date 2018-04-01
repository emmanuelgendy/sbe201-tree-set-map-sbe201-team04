cmake_minimum_required(VERSION 3.8)
project(sbe201_words)

set(CMAKE_CXX_STANDARD 14)

add_executable(sbe201_test_tree test_tree.cpp)
add_executable(sbe201_unique_words unique_words.cpp)
add_executable(sbe201_count_words count_words.cpp)
add_executable(sbe201_count_dna countDNA.cpp)