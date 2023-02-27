#include "Kreis.h"
#include "Koordinate.h"
#include <iostream>



int main() {
    std::string input_line;
    while(std::cin) {
        std::cout << "input (kreis/rechteck)?";
        std::getline(std::cin, input_line);
        if(input_line == "kreis") {
            std::cout << "x";
            std::getline(std::cin, input_line);
        } else if(input_line == "rechteck") {

        } else {
            std::cout << "try again" << std::endl;
        }
    }
    Kreis k = Kreis();
    ZeichenElement& kreis = k;
    std::cout << "hi" << k.getKoordinate().getX() << k.getCircumrefrence() << std::endl;
}

Koordinate readKoordinate() {
    std::string input_line;
    std::cout << "x?";
    std::getline(std::cin, input_line);

}
