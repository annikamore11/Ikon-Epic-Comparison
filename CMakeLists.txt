cmake_minimum_required(VERSION 3.21)
project(M2OEP_ahmore)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP_ahmore
        main.cpp
        Resort.cpp
        Size.cpp
        SkiPass.cpp
        Comparison.cpp
        skiGraphs.R)

add_executable(Ski_Resort_Testing
        Ski_Resort_Testing.cpp
        Resort.cpp
        Size.cpp
        SkiPass.cpp
        Comparison.cpp)
