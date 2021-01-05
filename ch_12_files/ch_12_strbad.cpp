#include <cstring>

#include "ch_12_strbad.h"

int StringBad::num_strings = 0;

StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << num_strings << ": \"" << str
        << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[len];
    std::strcpy(str, "C++");
    num_strings++;
    std::cout << num_strings << ": \"" << str
        << "\" default object created\n";
}

StringBad::StringBad(const StringBad& s) {
    num_strings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    std::cout << num_strings << ": \"" << str
              << "\" object created(copy cstr)\n";
}

StringBad::~StringBad() {
    std::cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    std::cout << num_strings << " left\n";
    delete [] str;
}

StringBad& StringBad::operator=(const StringBad& s) {
    //protect ssignment to myself
    if (&s == this) return *this;
    delete[] str;
    str = new char[s.len + 1];
    std::strcpy(str, s.str);
    len = s.len;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const StringBad& s) {
    os << s.str;
    return os;
}
