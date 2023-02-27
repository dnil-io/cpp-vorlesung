#ifndef ZEICHENELEMENT_H
#define ZEICHENELEMENT_H

#include "Koordinate.h"
#include <iostream>

enum ZeichenType {
  RECHTECK,
  KREIS
};

class ZeichenElement {
  public:    
    Koordinate getKoordinate() const;
    virtual double getArea() = 0; 
    virtual double getCircumrefrence() = 0; //virtuell da implementierung für Kreis und Rechteck verschieden sind
    virtual operator std::string() const = 0;
    virtual ZeichenType getType() = 0;
  protected:
    ZeichenElement(const Koordinate koordinate) : koordinate(koordinate) {}
    //sinnvoll es bei protected Protected zu machen damit niemand ein ZeichenElement direkt implementiert
  private:        
    Koordinate koordinate;
};
#endif