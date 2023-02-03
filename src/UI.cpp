#include <iostream>
#include <string>

#include "../include/UI.h"
#include "../include/CNumber.h"

void NumberUI::run() {
  while (true) {
    NumberUI::readRepresentationMode();
    if(NumberUI::userMode == UserMode::input) {
      NumberUI::readNumber();
    } else {
      NumberUI::printNumber();
    }
    NumberUI::readUserMode();
    NumberUI::changeNumber();
  } 
}

void NumberUI::readRepresentationMode() {
  std::string representationMode;
  while(representationMode != "c" && representationMode != "p") {
    std::cout << "representation mode? (c/p): ";
    std::getline(std::cin, representationMode);

    if(representationMode == "c") {
      NumberUI::representationMode = RepresentationMode::cartesian;
      break;
    } else if (representationMode == "p") {
      NumberUI::representationMode = RepresentationMode::polar;
      break;
    }
    std::cout << "try again. \n" ;
  }
}

void NumberUI::readUserMode() {
  std::string representationMode;
  while(representationMode != "i" && representationMode != "o") {
    std::cout << "input or output? (i/o): ";
    getline(std::cin, representationMode);

    if(representationMode == "i") {
      NumberUI::userMode = UserMode::input;
      break;
    } else if (representationMode == "o") {
      NumberUI::userMode = UserMode::output;
      break;
    }
    std::cout << "try again. \n" ;
  }
}

void NumberUI::readNumber() {
  std::string buffer;
  char* parseResult;
  while(true) {
    std::cout << "a: ";
    std::getline(std::cin, buffer);
    double convertedI = strtod(buffer.c_str(), &parseResult);
    if(*parseResult) {
      std::cout << "try again\n";
      continue;
    }
    std::cout << "b: ";
    std::getline(std::cin, buffer);
    double convertedII = strtod(buffer.c_str(), &parseResult);

    if(*parseResult) {
      std::cout << "try again\n";
      continue;
    }

    if(representationMode == RepresentationMode::cartesian) {
      CartesianCoordinates coords = {convertedI, convertedII};
      number.setCartesian(&coords);
      break;
    } else if (representationMode == RepresentationMode::polar) {
      PolarCoordinates coords = {convertedI, convertedII};
      number.setPolar(&coords);      
      break;
    }
  }
}

void NumberUI::changeNumber() {
    std::string changeRequest;
    std::cout << "Do you want to cahnge any number/parameter? (y/n): ";
    getline(std::cin,changeRequest);
    if (changeRequest == "y") {
        std::string changeAmount;
        std::cout << "Do you want to change one or two numbers/Parameters? (1/2): ";
        getline(std::cin, changeAmount);
        if (changeAmount == "2") {
            NumberUI::readNumber();
        }else if(changeAmount == "1") {
            std::cout << "change one";
        }
        else {
            std::cout << "change aborded dur to illegal statement";
        }
    }
}

void NumberUI::printNumber() {
  if(representationMode == RepresentationMode::cartesian) {
    CartesianCoordinates coords = number.getCartesian();
    std::cout << "a: " << coords.a << "; b:" << coords.b << std::endl;
  } else if (representationMode == RepresentationMode::polar) {
    PolarCoordinates coords = number.getPolar();
    std::cout << "r: " << coords.r << "; phi:" << coords.phi << "rad" << std::endl;
  }
}