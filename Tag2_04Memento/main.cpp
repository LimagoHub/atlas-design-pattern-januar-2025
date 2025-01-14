#include <iostream>
#include "tiere/Schwein.h"

int main() {
    Schwein piggy;

    std::cout << piggy << std::endl;

    auto memento = piggy.getMemento();

    piggy.fuettern();

    std::cout << piggy << std::endl;

    // wieder herstellen
    piggy.setMemento(memento);
    std::cout << piggy << std::endl;

}