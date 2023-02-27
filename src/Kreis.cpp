#include "Kreis.h"
#define PI 3.14
#include <iostream>
#include <cmath>

double Kreis::getArea() {
    return std::abs(this->radius * this->radius * 2 * PI);
}

double Kreis::getCircumrefrence() {
    return std::abs(this->radius * 2 * PI);
}

ZeichenType Kreis::getType() {
    return ZeichenType::KREIS;
}

Kreis::operator std::string() const {
    return "kreis! koordinaten: " + static_cast<std::string>(this->getKoordinate())+ "; radius: " + std::to_string(this->radius);
}