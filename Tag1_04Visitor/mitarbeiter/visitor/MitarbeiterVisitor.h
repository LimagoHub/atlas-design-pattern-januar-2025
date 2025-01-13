//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once
namespace mitarbeiter {
    class GehaltsEmpfaenger;
    class LohnEmpfaenger;
}
namespace mitarbeiter::visitor {

    class MitarbeiterVisitor {
    public:
        virtual void init() = 0;
        virtual ~MitarbeiterVisitor() = default;
        virtual void visit(mitarbeiter::LohnEmpfaenger &lohn_empfaenger) = 0;

        virtual void visit(mitarbeiter::GehaltsEmpfaenger &gehalts_empfaenger) = 0;
        virtual void dispose() = 0;
    };

} // visitor
