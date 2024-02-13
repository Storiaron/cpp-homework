cmake_minimum_required(VERSION 3.26)
project(cpp-homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-homework main.cpp
        simulation_library/Simulator.cpp
        simulation_library/Simulator.h
        simulation_library/Cell.cpp
        simulation_library/Cell.h
        simulation_library/Configuration.cpp
        simulation_library/Configuration.h
        simulation_library/FileWriter.cpp
        simulation_library/FileWriter.h
        simulation_library/test/ConfigurationTester.cpp
        simulation_library/test/ConfigurationTester.h
        simulation_library/test/SimulatorTester.cpp
        simulation_library/test/SimulatorTester.h
        Application.cpp
        Application.h
)
