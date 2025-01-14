//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once

#include <iostream>
#include "CharacterHandler.h"
namespace processor::handler  {

    class LineCounter : public CharacterHandler{
        int counter{0};

    protected:
        void init() override {
            counter = 0;
        }

        void dispose() override {
            std::cout << counter << std::endl;
        }

        void process(char c) override {
            if(c == '\n') counter ++;
        }
    };

} // processor
