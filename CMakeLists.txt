cmake_minimum_required(VERSION 3.6)
project(long_arithmetic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Bignum.cpp src/Bignum.h src/BignumException.h src/NotNumberException.h src/OutOfBoundsException.h src/ZeroDivideException.h src/NegativeRootException.h src/OverflowException.h)
add_executable(long_arithmetic ${SOURCE_FILES})