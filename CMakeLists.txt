cmake_minimum_required(VERSION 3.23)
project(ex2_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2_1
        Card.h
        Mtmchkin.h
        Player.cpp
        Player.h
        test.cpp
        utilities.cpp
        utilities.h)
