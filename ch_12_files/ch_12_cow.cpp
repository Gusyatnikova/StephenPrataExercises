#include "ch_12_cow.h"

#include <iostream>

Cow::Cow() {
    name[0] = '\0';
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
    std::strncpy(name, nm, 20);
    int hobby_len = strlen(ho);
    hobby = new char[hobby_len + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow& c) : Cow(c.name, c.hobby, c.weight) {
    /*std::strncpy(name, c.name, 20);
    int hobby_len = std::strlen(c.hobby);
    hobby = new char[hobby_len + 1];
    std::strcpy(c.hobby, hobby);
    weight = c.weight;*/
}

Cow::~Cow() {
    delete[] hobby;
}

Cow& Cow::operator=(const Cow& c) {
    if (this == &c) return *this;
    std::strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const {
    if (std::strlen(name) == 0) {
        std::cout << "empty\n";
        return;
    }
    std::cout << "name: " << name << std::endl
              << "hobby: " << hobby << std::endl
              << "weight: " << weight << std::endl;
}