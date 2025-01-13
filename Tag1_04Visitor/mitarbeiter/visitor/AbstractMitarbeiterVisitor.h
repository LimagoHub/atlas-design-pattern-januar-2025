//
// Created by JoachimWagner on 13.01.2025.
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
    };

} // visitor
