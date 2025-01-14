cmake_minimum_required(VERSION 3.17)
project(Tag2_04Memento)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_04Memento main.cpp
        tiere/Schwein.h
        tiere/SchweineMemento.h)
