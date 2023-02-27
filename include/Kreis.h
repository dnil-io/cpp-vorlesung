#ifndef KREIS_H
#define KREIS_H

#include "ZeichenElement.h"

class Kreis : public ZeichenElement 
{
public:
    Kreis(Koordinate center = Koordinate(), int radius = 777) : ZeichenElement(center), radius(radius) {}
    int getRadius();
    virtual double getArea();
    virtual double getCircumrefrence();
private:
    int radius;
};

#endif
