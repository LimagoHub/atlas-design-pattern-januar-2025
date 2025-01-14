#include <iostream>
#include "tiere/Schwein.h"

class Metzger {
public:
    void schlachten (Tier * schwein) {
        std::cout << " Messer wetz" << std::endl;
    }
};

template<class T>
class Spediteur {
public:
    void fahren (T * ware) {
        std::cout << "wir fahren auf der Autobahn" << std::endl;
    }
};


int main() {

    Metzger metzger;
    Spediteur<Schwein> spediteur;
    Schwein piggy{"Miss piggy"};

    piggy.addPigTooFatListener([&metzger](Tier *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener([&spediteur](Schwein *s){spediteur.fahren(s);});


    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
}