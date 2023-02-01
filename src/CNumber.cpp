#include <cmath>
#include "../include/CNumber.h"

void CNumber::setCartesian(CartesianCoordinates* coords) {
  a = coords->a;
  b = coords->b;
}

void CNumber::setPolar(PolarCoordinates* coords) {
  a = coords->r * (cos(coords->phi));
  b = coords->r * (sin(coords->phi));
}

PolarCoordinates CNumber::getPolar() {
  PolarCoordinates result;

  result.r = sqrt(a*a + b*b);
  result.phi = atan(b / a);

  return result;
}

CartesianCoordinates CNumber::getCartesian() {
  CartesianCoordinates result;

  result.a = a;
  result.b = b;

  return result;
}