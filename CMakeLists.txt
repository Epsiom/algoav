cmake_minimum_required(VERSION 3.3)
project(Repository)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.cpp Node.cpp)
add_executable(Repository ${SOURCE_FILES})