//
// Created by JoachimWagner on 29.10.2024.
//

#pragma once


#include "../math/Calculator.h"

#include "AbstractQuery.h"

using Calc=math::Calculator;

namespace command {

    class SubCommand : public AbstractQuery {
        double value{0};
    public:
        SubCommand()=default;
        ~SubCommand() override = default;

        auto parse(const StringVector &tokens)->void override {
            value = std::stod(tokens[1]);
        }

        auto undo() -> void override {
            Calc::getInstance()->add(value);
        }

        auto isQuery()->bool override {
            return false;
        }

        auto execute()->void override {
            Calc::getInstance()->sub(value);
        }
    };
}