cmake_minimum_required(VERSION 3.8)
project(CSE321_Project_1 C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FL AGS "-std=c++11")

add_library(ControlCenter OBJECT ControlCenter.h)
add_library(Drone OBJECT Drone.h)
add_executable(DCAS ControlCenter.cpp Drone.cpp Driver.cpp Coordinate.cpp)