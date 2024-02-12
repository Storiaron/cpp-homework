cmake_minimum_required(VERSION 3.26)
project(cpp-homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-homework main.cpp
        Simulator.cpp
        Simulator.h
        Cell.cpp
        Cell.h
        Configuration.cpp
        Configuration.h
        FileWriter.cpp
        FileWriter.h
)
