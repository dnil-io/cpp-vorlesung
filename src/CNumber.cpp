#include <cmath>
#include "../include/CNumber.h"

CartesianCoordinates CNumber::getAsCartesian() {
    return this->cartesianCoordinates;
}

PolarCoordinates CNumber::getAsPolar() {
    return this->polarCoordinates;
}

void CNumber::setCartesian(std::optional<double> x, std::optional<double> y) {
    auto coords = CartesianCoordinates{
            .x =  x.value_or(this->getAsCartesian().x),
            .y =  y.value_or(this->getAsCartesian().y)
    };

    this->cartesianCoordinates = coords;
    this->polarCoordinates = fromCartesian(coords);
}

void CNumber::setPolar(std::optional<double> r, std::optional<double> phi) {
    auto coords = PolarCoordinates{
            .r = r.value_or(this->getAsPolar().r),
            .phi = phi.value_or(this->getAsPolar().phi)
    };

    this->polarCoordinates = coords;
    this->cartesianCoordinates = fromPolar(coords);
}


PolarCoordinates CNumber::fromCartesian(CartesianCoordinates &coords) {
    return PolarCoordinates{
            .r = sqrt(pow(coords.x, 2) + pow(coords.y, 2)),
            .phi = atan2(coords.y, coords.x)
    };
}

CartesianCoordinates CNumber::fromPolar(PolarCoordinates &coords) {
    return CartesianCoordinates{
        .x = coords.r * cos(coords.phi),
        .y = coords.r * sin(coords.phi)
    };
}
