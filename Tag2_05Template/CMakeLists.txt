cmake_minimum_required(VERSION 3.17)
project(Tag2_05Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_05Template main.cpp
        processor/handler/CharacterCounter.h
        processor/handler/LineCounter.h)
