//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <iostream>
#include "../math/Calculator.h"


namespace client {

    class Client {

        math::Calculator &calculator_;

    public:

        explicit Client(math::Calculator &calculator) : calculator_(calculator) {}

        void go() {
            std::cout << calculator_.add(2,3) <<std:: endl;
        }


    };

} // client
