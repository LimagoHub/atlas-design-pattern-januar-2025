//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include "Calculator.h"

namespace math {

    class CalculatorImpl : public Calculator {

    public:

        CalculatorImpl() = default;

        ~CalculatorImpl() override = default;

        double add(double a, double b) override {
            return a + b;
        }

        double sub(double a, double b) override {
            return a -b;
        }

    };

} // math
