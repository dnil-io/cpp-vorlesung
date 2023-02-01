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

void NumberUI::printNumber() {
  if(representationMode == RepresentationMode::cartesian) {
    CartesianCoordinates coords = number.getCartesian();
    std::cout << "a: " << coords.a << "; b:" << coords.b << std::endl;
  } else if (representationMode == RepresentationMode::polar) {
    PolarCoordinates coords = number.getPolar();
    std::cout << "r: " << coords.r << "; phi:" << coords.phi << "rad" << std::endl;
  }
}