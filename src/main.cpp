#include "Kreis.h"
#include "Rechteck.h"
#include "Koordinate.h"
#include "ZeichenElement.h"
#include <iostream>

ZeichenElement* storage[10] = {}; 
int storageIndex = 0;

int readInt(std::string prompt) {
    std::string input_line;
    std::cout << prompt << "?: ";
    std::getline(std::cin, input_line);
    return std::stoi(input_line);
}

Koordinate readKoordinate() {
    return Koordinate(readInt("x"), readInt("y"));
}

void printStorageItem(int index) {
    std::string output = *storage[index];
    std::cout << output << std::endl;
}

void printStorage(ZeichenType filter, bool filterB) {
    double circumrefrence = 0;
    double area = 0;
    if(storageIndex < 10) {
        for(int i = 0; i < storageIndex; i++) {
            if((*storage[i]).getType() == filter && filterB) {
                printStorageItem(i);
                circumrefrence += (*storage[i]).getCircumrefrence();
                area += (*storage[i]).getArea();
            } else if(!filterB) {
                printStorageItem(i);
            }
        }
    } else {
        for(int i = 0; i < 10; i++) {
            int calcIndex = (storageIndex+i) % 10;
            if((*storage[calcIndex]).getType() == filter && filterB) {
                printStorageItem(calcIndex);
                circumrefrence += (*storage[calcIndex]).getCircumrefrence();
                area += (*storage[calcIndex]).getArea();
            } else if(!filterB) { 
                printStorageItem(calcIndex);
            }
        }
    }
    if (filterB) {
        std::cout << "umfang: "<< circumrefrence << std::endl;
        std::cout << "fläche: "<< area << std::endl;
    }
}

int main() {
    std::string input_line;
    while(std::cin) {
        std::cout << "input (kreis/rechteck)?";
        std::getline(std::cin, input_line);
        ZeichenElement* el;
        if(input_line == "kreis") {
            Koordinate koordinate = readKoordinate();
            Kreis* k = new Kreis(koordinate, readInt("radius"));
            el = k;
        } else if(input_line == "rechteck") {
            Koordinate koordinate = readKoordinate();
            Rechteck* r = new Rechteck(koordinate, readInt("height"), readInt("width"));
            el = r;
        } else {
            std::cout << "try again" << std::endl;
            continue;
        }
        storage[(storageIndex++) % 10] = el; 
        std::cout << "user input: " << std::endl;
        
        printStorage(ZeichenType::KREIS, false);
        
        std::cout << "sorted: " << std::endl;
        std::cout << "kreise: " << std::endl;
        printStorage(ZeichenType::KREIS, true); 
        std::cout << std::endl << "rechtecke: " << std::endl;
        
        printStorage(ZeichenType::RECHTECK, true);


    }
}

/*
Zu Aufgabe 7:
Es gibt bereits perfekt nutzbare Exception Klassen die aus std kommen. 
In dem Fall wäre es "std::invalid_argument" und wird bereits von std::stoi geworfen.
*/