//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once
#include "../math/Calculator.h"

#include "AbstractCommand.h"

using Calc=math::Calculator;

namespace command {

    class ClearCommand : public AbstractCommand {
        double value{0.0};
    public:
        ClearCommand()=default;
        ~ClearCommand() override = default;

        auto execute()->void override {
            value = Calc::getInstance()->getMemory();
            Calc::getInstance()->clear();
        }

        auto undo() -> void override {
            Calc::getInstance()->setMemory(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };
}