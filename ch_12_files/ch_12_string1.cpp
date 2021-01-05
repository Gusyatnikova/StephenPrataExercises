#include <cstring>

#include "ch_12_string1.h"

int String1::num_strings = 0;

String1::String1(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    ++num_strings;
}

String1::String1() {
    len = 0;
    //str = new char[1];
    //*str = '\0';
    str = nullptr;
    ++num_strings;
}

String1::String1(const String1 &s) {
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    ++num_strings;
}

String1::~String1() {
    --num_strings;
    delete[] str;
}

String1 &String1::operator=(const String1 &s) {
    //protect assignment to myself
    if (&s == this) return *this;
    delete[] str;
    str = new char[s.len + 1];
    std::strcpy(str, s.str);
    len = s.len;
    return *this;
}

String1 &String1::operator=(const char* c_str) {
    delete[] str;
    len = std::strlen(c_str);
    str = new char[len + 1];
    std::strcpy(str, c_str);
    return *this;
}

const char &String1::operator[](int i) const {
    return *(str + i);
}

char &String1::operator[](int i) {
    //i[str] is the same =)
    return *(str + i);
}


std::ostream &operator<<(std::ostream &os, const String1 &s) {
    os << s.str;
    return os;
}

int String1::HowMany() {
    return num_strings;
}

bool operator==(const String1 &lhs, const String1 &rhs) {
    return (lhs.len == rhs.len) && std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator<(const String1 &lhs, const String1 &rhs) {
    return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const String1 &lhs, const String1 &rhs) {
    return rhs < lhs;
}

std::istream &operator>>(std::istream &is, String1 &str) {
    char temp[String1::CINLIM];
    is.get(temp, String1::CINLIM);
    if (is)
        str = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}

