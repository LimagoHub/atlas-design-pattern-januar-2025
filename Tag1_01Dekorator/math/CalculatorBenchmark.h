//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once

#include <iostream>
#include <memory>
#include "Calculator.h"
#include <chrono>
namespace math {

    class CalculatorBenchmark: public Calculator {

        std::unique_ptr<Calculator> calculator_;

    public:

        explicit CalculatorBenchmark(std::unique_ptr<Calculator> calculator) : calculator_(std::move(calculator)) {}

        double add(double a, double b) override {

            auto start_ = std::chrono::high_resolution_clock::now();
            auto result = calculator_->add(a, b);
            auto end_ = std::chrono::high_resolution_clock::now();

            std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;


            return result;
        }

        double sub(double a, double b) override {
            return calculator_->sub(a, b);
        }
    };

} // math
