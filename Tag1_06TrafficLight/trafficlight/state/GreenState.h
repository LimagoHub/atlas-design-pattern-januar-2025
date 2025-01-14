//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <iostream>
#include "AbstractTrafficLightColorState.h"
namespace trafficlight::state {
    class GreenState : public AbstractTrafficLightColorState{

    public:
        GreenState(trafficlight::TrafficLight *trafficLight) : AbstractTrafficLightColorState(trafficLight) {}

        std::string getColor() {
            return "GREEN";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->red;
        }


    };
}
