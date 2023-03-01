#include "Kreis.h"
#include "Rechteck.h"
#include "Koordinate.h"
#include "ZeichenElement.h"
#include <iostream>
#include <stdlib.h>

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

void printStorage() {
    double circumrefrence = 0;
    double area = 0;
    
    for(int i = 0; i < std::min(storageIndex, 10); i++) {
        int calcIndex = ((storageIndex > 10 ? storageIndex : 0) + i) % 10; //
        printStorageItem(calcIndex);
        circumrefrence += (*storage[calcIndex]).getCircumrefrence();
        area += (*storage[calcIndex]).getArea();
    }
    
    std::cout << "Umfang: "<< circumrefrence << std::endl;
    std::cout << "Fläche: "<< area << std::endl;
}

void printStorageSorted(ZeichenType filter) {
    double circumrefrence = 0;
    double area = 0;

    for(int i = 0; i < std::min(storageIndex, 10); i++) {
        int calcIndex = ((storageIndex > 10 ? storageIndex : 0) + i) % 10;
        if((*storage[calcIndex]).getType() == filter) {
            printStorageItem(calcIndex);
            circumrefrence += (*storage[calcIndex]).getCircumrefrence();
            area += (*storage[calcIndex]).getArea();
        }
    } 

    std::cout << "Umfang: "<< circumrefrence << std::endl;
    std::cout << "Fläche: "<< area << std::endl;

}

void input_menu() {
    std::string input_line;
    std::cout << "Zeichenelement erstellen \n\n1: Kreis\n2: Rechteck\n\n> ";
    std::getline(std::cin, input_line);
    ZeichenElement* el;
    if(input_line == "1") {
        Koordinate koordinate = readKoordinate();
        Kreis* k = new Kreis(koordinate, readInt("radius"));
        el = k;
    } else if(input_line == "2") {
        Koordinate koordinate = readKoordinate();
        Rechteck* r = new Rechteck(koordinate, readInt("height"), readInt("width"));
        el = r;
    } else {
        std::cout << "-- NO VALID INPUT, USE \"kreis\" or \"rechteck\" --" << std::endl;
        return;
    }
    storage[(storageIndex++) % 10] = el; 
}

void output_menu() {
    std::string input_line;
    std::cout << "Zeichenelemente anzeigen \n\n1: in Reihenfolge der Eingabe(gemischt)\n2: sortiert: erst Kreise dann Rechtecke\n\n> ";
    std::getline(std::cin, input_line);
    ZeichenElement* el;
    if(input_line == "1") {
        std::cout << "\nin Reihenfolge der Eingabe(gemischt):\n\n";
        printStorage();
    } else if(input_line == "2") {
        std::cout << "\nsortiert: erst Kreise dann Rechtecke\n\n";
        std::cout << "Kreise: " << std::endl;
        printStorageSorted(ZeichenType::KREIS); 
        std::cout << std::endl << "Rechtecke: " << std::endl;
        printStorageSorted(ZeichenType::RECHTECK);
    } else {
        std::cout << "-- NO VALID INPUT, USE \"1\" or \"2\" --" << std::endl;
    }
}

void menu() {
    std::string input_line;
    std::cout << "MENU \n\n1: Zeichenelement erstellen\n2: Zeichenelemente anzeigen\n3: Programm beenden\n\n> ";
    std::getline(std::cin, input_line);
    if(input_line == "1") {
        input_menu();
    } else if(input_line == "2") {
        output_menu();
    } else if(input_line == "3") {
        std::cout << "\nGoing to sleep!\nError: The operation failed successfully\n";
        std::exit(0);
    } else {
        std::cout << "-- NO VALID INPUT, USE \"1\", \"2\" or \"3\" --" << std::endl;
    }
}

int main() {
    while(std::cin) {
        menu();
    }
}

/*
Zu Aufgabe 7:
Es gibt bereits perfekt nutzbare Exception Klassen die aus std kommen. 
In dem Fall wäre es "std::invalid_argument" und wird bereits von std::stoi geworfen.
*/