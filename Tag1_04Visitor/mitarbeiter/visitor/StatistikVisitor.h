//
// Created by JoachimWagner on 15.01.2024.
//

#pragma once

#include <ostream>
#include <iostream>
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"
namespace mitarbeiter::visitor {

    class StatistikVisitor :public MitarbeiterVisitor{
        size_t lohnCounter;
        size_t gehaltsCounter;


    public:

        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            ++ lohnCounter;
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            ++ gehaltsCounter;
        }

        void init() override {
            lohnCounter = gehaltsCounter = 0;
        }

        void dispose() override {
            std::cout << *this << std::endl;
        }

        size_t getLohnCounter() const {
            return lohnCounter;
        }

        size_t getGehaltsCounter() const {
            return gehaltsCounter;
        }

        size_t getGesamtCounter() const {
            return lohnCounter + gehaltsCounter;
        }

        friend std::ostream &operator<<(std::ostream &os, const StatistikVisitor &visitor) {
            os <<  " lohnCounter: " << visitor.lohnCounter
               << " gehaltsCounter: " << visitor.gehaltsCounter << " gesamtCounter: " << visitor.getGesamtCounter();
            return os;
        }
    };
}
