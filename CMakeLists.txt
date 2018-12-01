cmake_minimum_required(VERSION 3.12)
project(aoc2018)

set("${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra")

add_executable(aoc2018 main.cpp day1.cpp day1.h day1.txt day2.cpp day2.h)