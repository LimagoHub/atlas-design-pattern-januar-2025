#include <iostream>
#include <chrono>
#include "client/Client.h"

#include "math/CalculatorFactory.h"

using Calc_Pointer = std::unique_ptr<math::Calculator>;

int main() {

    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);
    math::CalculatorFactory::setBenchmark(true);

    auto calculator = math::CalculatorFactory::create();
    client::Client client{calculator};

    client.go();



    return 0;
}

