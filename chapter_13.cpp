#include <iostream>
#include <string>
#include "ch_13_files/classic.h"
#include "ch_13_files/dma.h"
#include "ch_13_files/port.h"

//13 - 1, 13 - 2
/*
void Bravo(const Cd &disk);

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano sonata in B flat, Fantasia in C", \
    "Alfred Brendel", "Philips", 2, 57.17  );
    Cd *pcd = &c1;
    std::cout << "Using objects directly:\n";
    c1.Report();
    c2.Report();
    std::cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    std::cout << "Testing assignment:\n";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

void Bravo(const Cd &disk) {
    disk.Report();
}*/
//13 - 3
/*const int SIZE = 3;

int main() {
    AbstractDMA *p_arr[SIZE];
    std::string label;
    int rating;
    std::string color;
    std::string style;
    char kind;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter label:";
        std::getline(std::cin, label);
        std::cout << "Enter kind (1 - 3):";
        while (std::cin >> kind &&
               (kind != '1' && kind != '2' && kind != '3')) {
            std::cout << "Enter either 1, 2 or 3:\n";
        }
        switch (kind) {
            case '1' :
                std::cout << "Enter rating:";
                std::cin >> rating;
                p_arr[i] = new baseDMA(label, rating);
                break;
            case '2' :
                while (std::cin.get() != '\n') continue;
                std::cout << "Enter color:";
                std::getline(std::cin, color);
                p_arr[i] = new lacksDMA(color, label);
                break;
            case '3' :
                while (std::cin.get() != '\n') continue;
                std::cout << "Enter style:";
                std::getline(std::cin, style);
                p_arr[i] = new hasDMA(style, label);
                break;
            default:
                break;
        }
        while (std::cin.get() != '\n') continue;
    }
    std::cout << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "p_arr[i]->View: ";
        p_arr[i]->View();
        std::cout << std::endl;
        std::cout << "std::cout << *arr[i]: ";
        std::cout << *p_arr[i];
        std::cout << std::endl;
    }
    for (int i = 0 ; i < SIZE; ++i) {
        delete p_arr[i];
    }
    std::cout << "Done!\n";
    return 0;
}*/
//13 - 4

int main() {
    return 0;
}