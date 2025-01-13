//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <memory>
#include "state/State.h"

class StateA;
class StateB;

class FrontController {
private:
    std::shared_ptr<State> stateA;
    std::shared_ptr<State> stateB;
    std::shared_ptr<State> current;
public:
    FrontController();



    virtual void drucken() {
        current->drucken();
    }
    virtual void changeToA(){
        current->changeToA();
    }
    virtual void changeToB() {
        current->changeToB();
    }

    friend class StateA;
    friend class StateB;
};
