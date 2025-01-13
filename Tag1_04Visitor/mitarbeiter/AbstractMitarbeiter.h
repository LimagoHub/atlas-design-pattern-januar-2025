//
// Created by JoachimWagner on 13.01.2025.
//

#pragma once

#include <string>
#include <ostream>
#include "visitor/MitarbeiterVisitor.h"

using VISITOR=mitarbeiter::visitor::MitarbeiterVisitor;
namespace mitarbeiter {

    class AbstractMitarbeiter {
        std::string name;

    public:
        explicit AbstractMitarbeiter(const std::string &name = "Fritz") : name(name) {}

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            AbstractMitarbeiter::name = name;
        }

        virtual std::string toString() const {
            return "Name = " + getName();
        }

        virtual void accept(VISITOR &visitor) = 0;

        friend std::ostream &operator<<(std::ostream &os, const AbstractMitarbeiter &abstractMitarbeiter) {
            os << abstractMitarbeiter.toString();
            return os;
        }
    };

} // mitarbeiter
