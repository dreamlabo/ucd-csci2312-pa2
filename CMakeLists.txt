cmake_minimum_required(VERSION 3.3)
project(PA3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp point.cpp point.h point.cpp point.h cluster.cpp cluster.h)
add_executable(PA3 ${SOURCE_FILES})