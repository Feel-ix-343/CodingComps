cmake_minimum_required(VERSION 3.21)
project(2022Jan)

set(CMAKE_CXX_STANDARD 17)

add_executable(2022Jan main.cpp)

add_executable(NonTransitiveDice NonTransitiveDice.cpp)
add_executable(Drought Drought.cpp)