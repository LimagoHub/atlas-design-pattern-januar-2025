//
// Created by JoachimWagner on 29.10.2024.
//



#pragma once
#include <stdexcept>
#include "../TrafficLight.h"
#include "AbstractTrafficLightState.h"


namespace trafficlight::state {
    class AbstractTrafficLightColorState : public AbstractTrafficLightState {
    protected:
        explicit AbstractTrafficLightColorState(TrafficLight *trafficLight) : AbstractTrafficLightState(trafficLight) {}

    public:
        ~AbstractTrafficLightColorState() override = default;



        void switchOff() override {
            getTrafficLight()->current = getTrafficLight()->off;
        }



    };
}
