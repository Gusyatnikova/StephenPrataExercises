#include <cstring>
#include <iostream>
#include "classic.h"

Cd::Cd(const char *p, const char *l,
       int s, double pt) {
    //std::strncpy(performers, p, 49);
    //std::strncpy(label, l, 19);
    performers = new char [std::strlen(p) + 1];
    label = new char [std::strlen(l) + 1];
    std::strcpy(performers, p);
    std::strcpy(label, l);
    selections = s;
    playtime = pt;
}

Cd::Cd(const Cd &src) {
    //std::strncpy(performers, src.performers, 49);
    //std::strncpy(label, src.label, 19);
    performers = new char [std::strlen(src.performers) + 1];
    label = new char [std::strlen(src.label) + 1];
    std::strcpy(performers, src.performers);
    std::strcpy(label, src.label);
    selections = src.selections;
    playtime = src.playtime;
}

Cd::Cd() {
    performers = label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd() {
    delete [] label;
    delete [] performers;
}

Cd &Cd::operator=(const Cd &c) {
    if (&c == this) return *this;
    delete [] performers;
    delete [] label;
    performers = new char [std::strlen(c.performers) + 1];
    label = new char [std::strlen(c.label) + 1];
    std::strcpy(performers, c.performers);
    std::strcpy(label, c.label);
    selections = c.selections;
    playtime = c.playtime;
    return *this;
}

void Cd::Report() const {
    std::cout << "---> Cd report:\n";
    std::cout << "Performers: " << performers << '\n'
              << "Label: " << label << '\n'
              << "Selections: " << selections << '\n'
              << "Play time: " << playtime << '\n';
    std::cout << "---> end Cd report\n";
}

Classic::Classic(const char *m, const char *p,
                 const char *l, int s, double pt)
        : Cd(p, l, s, pt) {
    main = new char[std::strlen(m) + 1];
    std::strcpy(main, m);
}

Classic::Classic(const Classic &c)
        : Cd(c) {
    main = new char [std::strlen(c.main) + 1];
    std::strcpy(main, c.main);
}

Classic::Classic() : main(nullptr) { }

Classic& Classic::operator=(const Classic &c) {
    if (&c == this) return *this;
    Cd::operator=(c);
    delete [] main;
    main = new char [std::strlen(c.main) + 1];
    std::strcpy(main, c.main);
    return *this;
}

Classic::~Classic() { delete [] main; }

void Classic::Report() const {
    std::cout << "---> Classic report:\n";
    Cd::Report();
    std::cout << "Main composition: " << main << '\n';
    std::cout << "---> end Classic report\n";
}