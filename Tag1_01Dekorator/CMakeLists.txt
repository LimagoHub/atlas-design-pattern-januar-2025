cmake_minimum_required(VERSION 3.30)
project(Tag1_01Dekorator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tag1_01Dekorator main.cpp
        math/CalculatorImpl.h
        client/Client.h
        math/CalculatorLogger.h
        math/CalculatorSecure.h
)
