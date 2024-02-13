cmake_minimum_required(VERSION 3.0)
project(cpp-homework)
add_subdirectory(simulation_library)
set(SOURCES
        main.cpp
        Application.cpp
)

add_executable(cpp-homework ${SOURCES})
target_link_libraries(cpp-homework simulation_library)
