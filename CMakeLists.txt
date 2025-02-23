cmake_minimum_required(VERSION 3.27.5)
project(gravity)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.6.1 COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(gravity main.cpp Simulation.cpp Cell.cpp Grid.cpp)


target_include_directories(gravity PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(gravity sfml-graphics)