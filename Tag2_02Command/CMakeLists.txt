cmake_minimum_required(VERSION 3.30)
project(Tag2_02Command)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag2_02Command main.cpp
        command/Command.h
        math/Calculator.h
        command/CommandFactory.h
        command/AddCommand.h
        command/PrintCommand.h
        command/CommandHistory.h)
