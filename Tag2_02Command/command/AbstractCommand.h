//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once
#include "Command.h"

#include "../math/Calculator.h"
#include <stdexcept>
using Calc=math::Calculator;
namespace command {

    class AbstractCommand:public Command {

    public:
        auto parse(const StringVector &tokens) -> void override {
            // Ok
        }



        auto undo() -> void override {
           throw std::logic_error{"Upps"};

        }

        auto isQuery() -> bool override {
            return true;
        }
    };

} // command
