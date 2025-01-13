//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <iostream>
#include "Calculator.h"
namespace math {

    class CalculatorSecure : public Calculator{
        std::unique_ptr<Calculator> calculator_;

    public:
        explicit CalculatorSecure(std::unique_ptr<Calculator> calculator) : calculator_(std::move(calculator)) {}

        ~CalculatorSecure() override = default;

        double add(double a, double b) override {
            std::cout << "Du kommst hier rein" << std::endl;
            return calculator_->add(a,b);
        }

        double sub(double a, double b) override {
            return calculator_->sub(a,b);
        }
    };

} // math
