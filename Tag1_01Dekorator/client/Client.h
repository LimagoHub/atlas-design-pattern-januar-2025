//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include "../math/Calculator.h"


namespace client {

    class Client {

        std::unique_ptr<math::Calculator> calculator_;

    public:

        explicit Client(std::unique_ptr<math::Calculator> &calculator) : calculator_(std::move(calculator)) {}

        void go() {
            std::cout << calculator_->add(2,3) <<std:: endl;
        }


    };

} // client
