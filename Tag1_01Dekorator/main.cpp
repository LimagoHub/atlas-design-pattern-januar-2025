#include <iostream>
#include <chrono>
#include "client/Client.h"
#include "math/CalculatorImpl.h"
#include "math/CalculatorLogger.h"
#include "math/CalculatorSecure.h"
int main() {

    math::CalculatorImpl impl;
    math::CalculatorLogger logger{impl};
    math::CalculatorSecure secure{logger};
    client::Client client{secure};

    client.go();

    auto start_ = std::chrono::high_resolution_clock::now();
    auto end_ = std::chrono::high_resolution_clock::now();

    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;

    return 0;
}

