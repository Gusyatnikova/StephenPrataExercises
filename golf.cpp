#include "golf.h"
#include <iostream>

void setgolf (golf& g, const char* name, int hc) {
    int i = 0;
    for (i = 0; i < Len; ++i) {
        if (name[i] == '\0') break;
        g.fullname[i] = name[i];
    }
    g.fullname[i] = '\0';
    g.handicap = hc;
}
int setgolf (golf& g) {
    std::cout << "Enter a name:\n";
    while (!std::cin.getline(g.fullname, Len)) {
        std::cout << "Enter correct name:\n";
        while(std::cin.get() != '\n') continue;
    }
    if (g.fullname[0] != '\0') {
        std::cout << "Enter a handicap:\n";
        while (!(std::cin >> g.handicap)) {
            std::cout << "Enter integer value of handicap:\n";
            while (std::cin.get() != '\n') continue;
        }
        std::cin.get();
    return 1;
    }
    return 0;
}
void handicap (golf& g, int hc) {
    g.handicap = hc;
}
void showgolf(const golf& g) {
    std::cout << g.fullname << "'s handicap is: " << g.handicap << std::endl;
}
