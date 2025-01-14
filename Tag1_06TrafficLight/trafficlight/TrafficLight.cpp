//
// Created by JoachimWagner on 28.10.2024.
//
#include <memory>
#include "TrafficLight.h"
#include "state/TrafficLightState.h"
#include "state/RedState.h"
#include "state/GreenState.h"
#include "state/OffState.h"



std::string trafficlight::TrafficLight::getColor() {
    return current->getColor();
}

void trafficlight::TrafficLight::nextColor() {
    current->nextColor();
}

trafficlight::TrafficLight::TrafficLight():
red(std::make_shared<trafficlight::state::RedState>(this)) ,
green(std::make_shared<trafficlight::state::GreenState>(this)),
off(std::make_shared<trafficlight::state::OffState>(this)),
current(off)
  {


}

void trafficlight::TrafficLight::switchOff() {
    current->switchOff();
}

void trafficlight::TrafficLight::switchOn() {
    current->switchOn();
}

