//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once


class Komplex {
    double real, imag;
    Komplex();
public:
    static Komplex fromCoord(double real, double imag);
    static Komplex fromPolar(double betrag, double winkel);

};
