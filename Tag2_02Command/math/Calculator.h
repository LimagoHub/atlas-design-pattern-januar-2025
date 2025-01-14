//
// Created by JoachimWagner on 14.01.2025.
//

#pragma once

#include <memory>
#include <iostream>

namespace math {

    class Calculator {
          Calculator() {}

          double memory{0};
       
          void setMemory(double memory) { // Bloede Funktion, soll spaeter weg
            Calculator::memory = memory;
          }
    public:
        [[nodiscard]] static auto getInstance()->std::shared_ptr<Calculator>  {
            static std::shared_ptr<Calculator> instance{new Calculator{}};

            return instance;
        }

        double getMemory() const {
            return memory;
        }


        auto print() const->void{
            std::cout << memory << std::endl;
        }
        auto clear()-> void {
            memory = 0;
        }

        auto add(double value)-> void {
            memory += value;
        }
        auto sub(double value)-> void {
            memory -= value;
        }
        auto mult(double value)-> void {
            memory *= value;
        }
        auto div(double value)-> void {
            memory /= value;
        }

    };

} // math
