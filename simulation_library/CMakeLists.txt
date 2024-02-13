cmake_minimum_required(VERSION 3.0)
project(simulation_library)
set(SOURCES
        Simulator.cpp
        Cell.cpp
        Configuration.cpp
        FileWriter.cpp
)
set(HEADERS
        Simulator.h
        Cell.h
        Configuration.h
        FileWriter.h
)
add_library(simulation_library ${SOURCES} ${HEADERS})
target_include_directories(simulation_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(simulation_library)
