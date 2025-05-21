#include <iostream>
#include "virtual_temperature.hpp"

int main() {
    std::vector<double> T = {283.0, 293.0, 303.0};
    std::vector<double> w = {0.012, 0.025, 0.064};
    //double T = 283.0; // Example temperature in Kelvin
    
    auto Tv = virtual_temperature(T, w);

    for (double val : Tv) {
        std::cout << "Virtual temperature: " << val << " K\n";
    }

    return 0;
}

