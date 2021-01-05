#pragma once

#include <iostream>

class String1 {
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String1();
    String1(const char* s);
    String1(const String1& str);
    ~String1();
    int length() const {return len;}

    String1& operator=(const String1& s);
    String1& operator=(const char* c_str);
    char& operator[](int i);
    const char &operator[](int i) const;

    static int HowMany();

    friend std::ostream& operator<<(std::ostream& os, const String1& st);
    friend std::istream& operator>>(std::istream& is, String1& st);
    friend bool operator<(const String1& lhs, const String1& rhs);
    friend bool operator>(const String1& lhs, const String1& rhs);
    friend bool operator==(const String1& lhs, const String1& rhs);
};