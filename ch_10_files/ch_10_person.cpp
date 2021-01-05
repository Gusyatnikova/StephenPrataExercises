#include <iostream>
#include "ch_10_person.h"
#include <cstring>

Person::Person(const std::string &ln, const char *fn) {
    lname = ln;
    for (int i = 0; i < LIMIT - 1; ++i) {
        if ('\0' != fn[i]) {
            fname[i] = fn[i];
        } else {
            fname[i] = '\0';
            break;
        }
    }
    fname[LIMIT - 1] = '\0';
}

void Person::Show() const {
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const {
    std::cout << lname << " " << fname << std::endl;
}