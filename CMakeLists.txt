cmake_minimum_required(VERSION 4.3)
project(CutOptimizer)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(optimize)

add_executable(CutOptimizer main.cpp
        display.cpp
        optimize/fileHandler.h)
target_link_libraries(CutOptimizer PRIVATE
        Qt6::Widgets
        optimize)
