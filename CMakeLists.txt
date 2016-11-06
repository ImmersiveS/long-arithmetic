cmake_minimum_required(VERSION 3.6)
project(long_arithmetic_v2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/LongArithmetic.cpp src/LongArithmetic.h)
add_executable(long_arithmetic_v2 ${SOURCE_FILES})