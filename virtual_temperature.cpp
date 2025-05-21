#include "virtual_temperature.hpp"
#include <stdexcept>

std::vector<double> virtual_temperature(
    const std::vector<double>& temperature,
    const std::vector<double>& mixing_ratio,
    double epsilon
) {
    if (temperature.size() != mixing_ratio.size()) {
        throw std::invalid_argument("Temperature and mixing ratio vectors must be the same size.");
    }

    std::vector<double> result;
    result.reserve(temperature.size());

    for (size_t i = 0; i < temperature.size(); ++i) {
        double T = temperature[i];
        double w = mixing_ratio[i];
        result.push_back(T * (w + epsilon) / (epsilon * (1 + w)));
    }

    return result;
}

std::vector<double> virtual_temperature(
    double temperature,
    const std::vector<double>& mixing_ratio,
    double epsilon
) {
    std::vector<double> temperature_vec(mixing_ratio.size(), temperature);
    return virtual_temperature(temperature_vec, mixing_ratio, epsilon);
}

std::vector<double> virtual_temperature(
    const std::vector<double>& temperature,
    double mixing_ratio,
    double epsilon
) {
    std::vector<double> mixing_ratio_vec(temperature.size(), mixing_ratio);
    return virtual_temperature(temperature, mixing_ratio_vec, epsilon);
}

