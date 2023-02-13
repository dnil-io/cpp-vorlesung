#include <iostream>
#include <string>

#include "../include/UI.h"
#include "../include/CNumber.h"

NumberUI::NumberUI()
{
}

void NumberUI::run() {
  NumberUI::readRepresentationMode();
  NumberUI::readNumber();
  while (true) {
    NumberUI::readUserMode();
    NumberUI::readRepresentationMode();
    if(NumberUI::userMode == UserMode::input) {
      NumberUI::changeNumber();
    } else {
      NumberUI::printNumber();
    }
  } 
}

void NumberUI::readRepresentationMode() {
  std::string representationMode;
  while(representationMode != "c" && representationMode != "p") {
    std::cout << "cartesian or polar? (c/p) : ";
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
    if(NumberUI::representationMode == polar){
        std::cout << "r: ";
    }else{
        std::cout << "a: ";
    }
    std::getline(std::cin, buffer);
    double convertedI = strtod(buffer.c_str(), &parseResult);
    if(*parseResult) {
      std::cout << "try again\n";
      continue;
    }
    if (NumberUI::representationMode == polar) {
        std::cout << "i: ";
    }
    else {
        std::cout << "b: ";
    }
    std::getline(std::cin, buffer);
    double convertedII = strtod(buffer.c_str(), &parseResult);

    if(*parseResult) {
      std::cout << "try again\n";
      continue;
    }

    if(representationMode == RepresentationMode::cartesian) {
      CartesianCoordinates coords = {convertedI, convertedII};
      number.setCartesian(std::make_optional(coords.x), std::make_optional(coords.y));
      break;
    } else if (representationMode == RepresentationMode::polar) {
      PolarCoordinates coords = {convertedI, convertedII};
      number.setPolar(std::make_optional(coords.r), std::make_optional(coords.phi));
      break;
    }
  }
}

void NumberUI::changeNumber() {
    if (NumberUI::userMode == UserMode::input) {
        std::string changeAmount;
        std::cout << "Do you want to change one or two numbers/parameters? (1/2): ";
        getline(std::cin, changeAmount);
        if (changeAmount == "2") {
            NumberUI::readNumber();
        }else if(changeAmount == "1") {
            std::string changingParameter;
            std::string changingValueStr;
            if (NumberUI::representationMode == polar) {
                std::cout << "What parameter do you want to change? (i/r): ";
                getline(std::cin, changingParameter);
                if(changingParameter == "i") {
                    std::cout << "i:";
                    getline(std::cin, changingValueStr);
                    number.setPolar(std::nullopt, std::make_optional(atof(changingValueStr.c_str())));
                }
                else
                {
                    std::cout << "r:";
                    getline(std::cin, changingValueStr);
                    number.setPolar(std::make_optional(atof(changingValueStr.c_str())), std::nullopt);
                }
            }
            else {
                std::cout << "What parameter do you want to change? (a/b): ";
                getline(std::cin, changingParameter);
                if (changingParameter == "a") {
                    std::cout << "a:";
                    getline(std::cin, changingValueStr);
                    number.setCartesian(std::nullopt, std::make_optional(atof(changingValueStr.c_str())));
                }
                else
                {
                    std::cout << "b:";
                    getline(std::cin, changingValueStr);
                    number.setCartesian(std::make_optional(atof(changingValueStr.c_str())), std::nullopt);
                }
            }
        }
        else {
            std::cout << "change aborded due to illegal statement";
        }

    }
}

void NumberUI::printNumber() {
  if(representationMode == RepresentationMode::cartesian) {
    CartesianCoordinates coords = number.getAsCartesian();
    std::cout << "x: " << coords.x << "; y:" << coords.y << std::endl;
  } else if (representationMode == RepresentationMode::polar) {
    PolarCoordinates coords = number.getAsPolar();
    std::cout << "r: " << coords.r << "; phi:" << coords.phi << "rad" << std::endl;
  }
}
