cmake_minimum_required(VERSION 3.3)
project(Repository)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES Blossom.cpp Node.cpp Graph.cpp EdmondsKarp.cpp)
add_executable(Couplage ${SOURCE_FILES})

