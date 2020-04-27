cmake_minimum_required(VERSION 3.15)
project(keygen)

set(CMAKE_CXX_STANDARD 14)

#add_executable(keygen main.cpp)
add_executable(keygen main.cpp keygen.cpp keygen.h keygen.cpp strcompile.cpp strcompile.h md5.cpp md5.h sha1.cpp sha1.h)
#add_library(keygen keygen.cpp keygen.h)