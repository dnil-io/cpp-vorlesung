#ifndef CNUMBER_H
#define CNUMBER_H

#include <optional>

struct PolarCoordinates {
    double r = 0, phi = 0;
};

struct CartesianCoordinates {
    double x = 0, y = 0;
};

class CNumber {
public:
    void setCartesian(std::optional<double> x = std::nullopt, std::optional<double> y = std::nullopt);

    void setPolar(std::optional<double> r = std::nullopt, std::optional<double> phi = std::nullopt);

    PolarCoordinates getAsPolar();

    CartesianCoordinates getAsCartesian();

private:
    PolarCoordinates polarCoordinates = PolarCoordinates{};
    CartesianCoordinates cartesianCoordinates = CartesianCoordinates{};

    static PolarCoordinates fromCartesian(CartesianCoordinates &coords);

    static CartesianCoordinates fromPolar(PolarCoordinates &coords);
};

#endif
