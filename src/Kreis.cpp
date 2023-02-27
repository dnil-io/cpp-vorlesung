#include "Kreis.h"
#define PI 3.14

double Kreis::getArea() {
    return this->radius + this->radius * 2 * PI;
}

double Kreis::getCircumrefrence() {
    return this->radius * 2 * PI;
}

