#ifndef CNUMBER_H
#define CNUMBER_H

#include <optional>

struct PolarCoordinates {
    double r = 0, phi = 0;
};

struct CartesianCoordinates {
    double x = 0, y = 0;
};

struct PracticeCartesianCoordinates {       //zu Aufg 2.4
    float x = 0, y = 0;


    PracticeCartesianCoordinates(float x_value, float y_value) : x(x_value), y(y_value) {}

};

class CNumber {
public:

    CNumber(PolarCoordinates c = { 1,2 }) : polarCoordinates(c) {}      //Constructer creates cartesian objects

    CNumber(CartesianCoordinates c = { 1,2 }) : cartesianCoordinates(c) {}      //Constructer creates polar objects

    CNumber(){}

   /* CNumber() : x(3), y(4)    is a comment because otherwise in UI.h the number Object dosent know which Constructor to use
    {
    
    }
    */

    CNumber(double a) {     //Aufg 2.5
        if (a < 0) {
            setPolar(a, 0.7853981634);
        }
        else {
            setPolar(a, -0.7853981634);
        }
    }


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
