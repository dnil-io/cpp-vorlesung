#include "../include/Koordinate.h"
#include <iostream>

int Koordinate::getX() {
    return this->x;
}
int Koordinate::getY() {
    return this->y;
}

Koordinate::operator std::string() const {
    std::string str = "x: "+ std::to_string(this->x) + "; y:" + std::to_string(this->y);
    return str;
}