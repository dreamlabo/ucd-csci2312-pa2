cmake_minimum_required(VERSION 3.3)
project(PA2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp point.cpp point.h cluster.cpp cluster.h)
add_executable(PA2 ${SOURCE_FILES})