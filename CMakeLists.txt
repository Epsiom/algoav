cmake_minimum_required(VERSION 3.3)
project(Repository)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES Blossom.cpp Node.cpp Graph.cpp)
add_executable(Algoavc ${SOURCE_FILES})