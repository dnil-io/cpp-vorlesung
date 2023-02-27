#ifndef KOORDINATE_H
#define KOORDINATE_H

class Koordinate {
public:
    //ist sinnvoll, sonst doppelte definition in Kreis sowie Rechteck von Standardwerten
    Koordinate(int x = 5, int y = 9) : x(x), y(y) {}

    int getX();
    int getY();
private:
    int x;
    int y;
};

#endif
