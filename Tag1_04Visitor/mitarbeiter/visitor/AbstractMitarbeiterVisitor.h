//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once
#include "MitarbeiterVisitor.h"
namespace mitarbeiter::visitor {
    class AbstractMitarbeiterVisitor: public MitarbeiterVisitor{

    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            // Ok
        }

        void visit(GehaltsEmpfaenger &gehalts_empfaenger) override {
            // Ok
        }

        void init() override {
            // Ok
        }

        void dispose() override {
            // Ok
        }
    };
}
