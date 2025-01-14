//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "Command.h"

#include "../math/Calculator.h"

using Calc=math::Calculator;
namespace command {

    class AddCommand:public Command {
        double value{0};
    public:
        auto parse(const StringVector &tokens) -> void override {
            value = std::stod(tokens[1]);
        }

        auto execute() -> void override {
            Calc::getInstance()->add(value);
        }

        auto undo() -> void override {
            Calc::getInstance()->sub(value);

        }

        auto isQuery() -> bool override {
            return false;
        }
    };

} // command
