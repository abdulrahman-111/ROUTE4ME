cmake_minimum_required(VERSION 3.29)
project(ROUTE4ME)

set(CMAKE_CXX_STANDARD 20)

add_executable(ROUTE4ME main.cpp
        "prim's .cpp"
        prim's.h
        graph.cpp
        graph.h
        SSSP.h
        SSSP.cpp)
