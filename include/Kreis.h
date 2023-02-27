#ifndef KREIS_H
#define KREIS_H

#include <iostream>
#include "ZeichenElement.h"

class Kreis : public ZeichenElement 
{
public:
    Kreis(Koordinate center = Koordinate(), int radius = 777) : ZeichenElement(center), radius(radius) {}
    int getRadius();
    virtual double getArea();
    virtual double getCircumrefrence();
    virtual ZeichenType getType();
    operator std::string() const;
private:
    int radius;
};

#endif
