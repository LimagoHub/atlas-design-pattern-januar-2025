//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <string>

namespace trafficLight {

    class TrafficLightState {

        virtual ~TrafficLightState();
        std::string getColor();
        void nextColor();

    };

} // trafficLight
