cmake_minimum_required(VERSION 3.14)
project(Matrix_Calc_With_Fractions)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)

add_executable(Matrix_Calc_With_Fractions main.cpp Matrix.cpp Matrix.h Vector.cpp Vector.h Numbers.cpp Numbers.h)

