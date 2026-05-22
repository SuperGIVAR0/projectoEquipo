cmake_minimum_required(VERSION 4.2)
project(projectoEquipo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projectoEquipo
        Asset.cpp
        Asset.h)
