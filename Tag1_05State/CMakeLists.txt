cmake_minimum_required(VERSION 3.17)
project(Tag1_05State)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_05State main.cpp
        FrontController.cpp
        FrontController.h
        state/State.h
        state/AbstractState.h
        state/StateA.h)
