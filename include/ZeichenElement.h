#ifndef ZEICHENELEMENT_H
#define ZEICHENELEMENT_H

#include "Koordinate.h"

class ZeichenElement {
  public:    
    Koordinate getKoordinate();
    virtual double getArea() = 0; 
    virtual double getCircumrefrence() = 0; //virtuell da implementierung für Kreis und Rechteck verschieden sind
  protected:
    ZeichenElement(Koordinate koordinate) : koordinate(koordinate) {}
    //sinnvoll es bei protected Protected zu machen damit niemand ein ZeichenElement direkt implementiert
  private:        
    Koordinate koordinate;
};
#endif