#include "Rechteck.h"
#include <iostream>
#include <cmath> 

double Rechteck::getArea() {
    return std::abs(this->width * this->height);
}

double Rechteck::getCircumrefrence() {
    return std::abs(this->width * 2 + this->height * 2);
}

ZeichenType Rechteck::getType() {
    return ZeichenType::RECHTECK;
}

Rechteck::operator std::string() const {
    return "rechteck! koordinaten: " + static_cast<std::string>(this->getKoordinate())+ "; width: " + std::to_string(this->width) + "; height: " +  std::to_string(this->height);
}