#include <cstring>

#include "ch_12_string2.h"

int String2::num_strings = 0;

String2::String2(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    ++num_strings;
}

String2::String2() {
    len = 0;
    //str = new char[1];
    //*str = '\0';
    str = nullptr;
    ++num_strings;
}

String2::String2(const String2 &s) {
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    ++num_strings;
}

String2::~String2() {
    --num_strings;
    delete[] str;
}

void String2::stringlow() {
    char* tmp = str;
    while(*tmp != '\0') {
        *tmp = std::tolower(*tmp);
        ++tmp;
    }
}

void String2::stringup() {
    char* tmp = str;
    while(*tmp != '\0') {
        *tmp = std::toupper(*tmp);
        ++tmp;
    }
}

int String2::has(char c) {
    int char_cnt = 0;
    for (char* i = str; *i != '\0'; ++i) {
        if (*i == c) ++char_cnt;
    }
    return char_cnt;
}

String2 &String2::operator=(const String2 &s) {
    //protect assignment to myself
    if (&s == this) return *this;
    delete[] str;
    str = new char[s.len + 1];
    std::strcpy(str, s.str);
    len = s.len;
    return *this;
}

String2 &String2::operator=(const char* c_str) {
    delete[] str;
    len = std::strlen(c_str);
    str = new char[len + 1];
    std::strcpy(str, c_str);
    return *this;
}

const char &String2::operator[](int i) const {
    return *(str + i);
}

char &String2::operator[](int i) {
    //i[str] is the same =)
    return *(str + i);
}


std::ostream &operator<<(std::ostream &os, const String2 &s) {
    os << s.str;
    return os;
}

int String2::HowMany() {
    return num_strings;
}

bool operator==(const String2 &lhs, const String2 &rhs) {
    return (lhs.len == rhs.len) && std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator<(const String2 &lhs, const String2 &rhs) {
    return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const String2 &lhs, const String2 &rhs) {
    return rhs < lhs;
}

std::istream &operator>>(std::istream &is, String2 &str) {
    char temp[String2::CINLIM];
    is.get(temp, String2::CINLIM);
    if (is)
        str = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}

String2 operator+(const String2& lhs, const String2& rhs) {
    char * result_str = new char[lhs.length() + rhs.length() + 1];
    std::strcpy(result_str, lhs.str);
    std::strcpy(result_str + lhs.length(), rhs.str);
    String2 sum(result_str);
    delete[] result_str;
    return sum;
}