#ifndef CNUMBER_H
#define CNUMBER_H

#include <optional>

struct PolarCoordinates {
    double r= 0, phi = 0;
};

struct CartesianCoordinates {
    double x = 0, y = 0;
};

class CNumber {
public:
    void setCartesian(std::optional<double> x, std::optional<double> y);

    void setPolar(std::optional<double> r, std::optional<double> phi);

    PolarCoordinates getAsPolar();

    CartesianCoordinates getAsCartesian();

private:
    PolarCoordinates polarCoordinates = PolarCoordinates {};
    CartesianCoordinates cartesianCoordinates = CartesianCoordinates {};

    static PolarCoordinates fromCartesian(CartesianCoordinates &coords);
    static CartesianCoordinates fromPolar(PolarCoordinates &coords);
};

#endif
