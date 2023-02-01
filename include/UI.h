#ifndef NUMBER_UI_H
#define NUMBER_UI_H

#include "CNumber.h"

enum RepresentationMode { cartesian, polar};
enum UserMode { input, output};

class NumberUI {
  public:    
    void run();
    void readUserMode();
    void readRepresentationMode();
    void readNumber();
    void printNumber();
  private:        
    RepresentationMode representationMode;
    UserMode userMode = input;
    CNumber number;
};
#endif