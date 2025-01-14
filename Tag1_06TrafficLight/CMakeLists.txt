cmake_minimum_required(VERSION 3.28)
project(Tag1_06TrafficLight)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag1_06TrafficLight main.cpp
        ../../atlas-design-pattern-januar-2025/Tag1_06TrafficLight/trafficLight/state/TrafficLightState.h
        trafficlight/TrafficLight.cpp
        trafficlight/TrafficLight.h
        ../../atlas-design-pattern-januar-2025/Tag1_06TrafficLight/trafficLight/state/AbstractTrafficLightState.h
        ../../atlas-design-pattern-januar-2025/Tag1_06TrafficLight/trafficLight/state/OffState.h
        ../../atlas-design-pattern-januar-2025/Tag1_06TrafficLight/trafficLight/state/AbstractTrafficLightColorState.h)
