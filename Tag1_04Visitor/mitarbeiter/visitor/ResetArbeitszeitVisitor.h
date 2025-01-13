//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once
#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"

namespace mitarbeiter::visitor {

    class ResetArbeitszeitVisitor : public AbstractMitarbeiterVisitor {
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            lohn_empfaenger.setArbeitszeit(0);
        }


    };
}
