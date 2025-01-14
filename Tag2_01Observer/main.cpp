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

    piggy.addPropertyChangedEventListener([](const PropertyChangedEvent<Schwein> &event){
        std::cout << event << std::endl;
    });

    piggy.addPigTooFatListener([&metzger](Tier *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener(std::bind(&Metzger::schlachten, &metzger, std::placeholders::_1));

    piggy.addPigTooFatListener([&spediteur](Schwein *s){spediteur.fahren(s);});


    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }

    piggy.setName("Babe");
}