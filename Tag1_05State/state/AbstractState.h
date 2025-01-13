//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once
#include <stdexcept>
#include "State.h"
#include "../FrontController.h"

class AbstractState : public State{

    FrontController * frontController;
protected:

    explicit AbstractState(FrontController *frontController) : frontController(frontController) {}

public:
    FrontController *getFrontController()  {
        return frontController;
    }

    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }
};
