#pragma once

#include <iostream>

class String2 {
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String2();
    String2(const char* s);
    String2(const String2& str);
    ~String2();
    int length() const {return len;}
    void stringlow();
    void stringup();
    int has(char c);

    String2& operator=(const String2& s);
    String2& operator=(const char* c_str);
    char& operator[](int i);
    const char &operator[](int i) const;

    static int HowMany();

    friend std::ostream& operator<<(std::ostream& os, const String2& st);
    friend std::istream& operator>>(std::istream& is, String2& st);
    friend bool operator<(const String2& lhs, const String2& rhs);
    friend bool operator>(const String2& lhs, const String2& rhs);
    friend bool operator==(const String2& lhs, const String2& rhs);
    friend String2 operator+(const String2& lhs, const String2& rhs);
};