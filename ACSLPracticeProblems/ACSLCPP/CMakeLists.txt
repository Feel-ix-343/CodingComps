cmake_minimum_required(VERSION 3.21)
project(ACSLCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ACSLCPP Soundex.cpp)

add_executable(ACSLble ACSLble.cpp)
add_executable(Tests Tests.cpp)