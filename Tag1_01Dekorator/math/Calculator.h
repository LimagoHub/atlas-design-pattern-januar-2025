//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

namespace math {

    class Calculator {

    public:
        virtual ~Calculator() = default;

        virtual double add(double a, double b) = 0;

        virtual double sub(double a, double b) = 0;
    };

} // math
