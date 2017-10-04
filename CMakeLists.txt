cmake_minimum_required(VERSION 3.8)
project(CSE321_Project_1)

set(CMAKE_CXX_STANDARD 11)

add_library(ControlCenter OBJECT ControlCenter.cpp)

add_executable(DCAS ControlCenter.cpp Drone.cpp Driver.cpp)