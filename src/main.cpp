#include "Kreis.h"
#include "Rechteck.h"
#include "Koordinate.h"
#include <iostream>

int readInt(std::string prompt) {
    std::string input_line;
    std::cout << prompt << "?: ";
    std::getline(std::cin, input_line);
    return std::stoi(input_line);
}

Koordinate readKoordinate() {
    return Koordinate(readInt("x"), readInt("y"));
}

int main() {
    std::string input_line;
    while(std::cin) {
        std::cout << "input (kreis/rechteck)?";
        std::getline(std::cin, input_line);
        ZeichenElement& el;
        if(input_line == "kreis") {
            el = Kreis(readKoordinate(), readInt("radius"));
        } else if(input_line == "rechteck") {
            el = Rechteck(readKoordinate(), readInt("height"), readInt("width"));

        } else {
            std::cout << "try again" << std::endl;
            continue;
        }
    }
    Kreis k = Kreis();
    ZeichenElement& kreis = k;
    std::cout << "hi" << k.getKoordinate().getX() << k.getCircumrefrence() << std::endl;
}