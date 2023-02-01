#ifndef CNUMBER_H
#define CNUMBER_H

struct PolarCoordinates {
  double r, phi;
};

struct CartesianCoordinates {
  double a, b;
};

class CNumber {
  public:    
    void setCartesian(CartesianCoordinates *coordinates);
    void setPolar(PolarCoordinates *coordinates);
    PolarCoordinates getPolar();
    CartesianCoordinates getCartesian();
  private:        
    double a, b;
};
#endif