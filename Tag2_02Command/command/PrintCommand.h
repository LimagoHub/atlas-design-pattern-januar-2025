//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "AbstractCommand.h"
namespace command {

    class PrintCommand :public AbstractCommand{
    public:
        auto execute() -> void override {
            Calc::getInstance()->print();
        }
    };

} // command
