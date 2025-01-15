#include <iostream>

#include "Person.h"
int main() {

    auto p = Person::builder()
            .withAnrede("Frau")
            .withNachname("Mustermann")
            .build();
    return 0;
}

