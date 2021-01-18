/*
#include "worker0.h"
#include <iostream>
#include <cstring>

const int SIZE = 5;

int main() {
    Worker *lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ++ct) {
        char choice;
        std::cout << "Enter the employee category:\n"
                  << "w: waiter s: singer t: singing water q: quit\n";
        std::cin >> choice;
        while(std::strchr("wstq", choice) == NULL) {
            std::cout << "Enter w, s, t, or q:";
            std::cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'w' :
                lolas[ct] = new Waiter;
                break;
            case 's' :
                lolas[ct] = new Singer;
                break;
            case 't':
                lolas[ct] = new SingingWaiter;
                break;
        }
        std::cin.get();
        lolas[ct]->Set();
    }
    std::cout << "\nHere is your stuff:\n";
    int i;
    for (i = 0; i < ct; ++i) {
        std::cout << std::endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; ++i) {
        delete lolas[i];
    }
    std::cout << "Bye!\n";
    return 0;
}*/
