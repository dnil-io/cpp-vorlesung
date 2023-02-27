#ifndef KOORDINATE_H
#define KOORDINATE_H
#include <iostream>

class Koordinate {
public:
    //ist sinnvoll, sonst doppelte definition in Kreis sowie Rechteck von Standardwerten
    Koordinate(int x = 5, int y = 9) : x(x), y(y) {}

    int getX();
    int getY();
    operator std::string() const;
private:
    int x;
    int y;
};

#endif
