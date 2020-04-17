cmake_minimum_required(VERSION 3.15)
project(keygen)

set(CMAKE_CXX_STANDARD 14)

#add_executable(keygen main.cpp)
add_executable(keygen main.cpp keygen.cpp keygen.h keygen.cpp)
#add_library(keygen keygen.cpp keygen.h)