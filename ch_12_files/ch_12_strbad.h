#pragma once

#include <iostream>

class StringBad {
private:
    char* str;
    int len;
    static int num_strings;
public:
    StringBad();
    StringBad(const char* s);
    StringBad(const StringBad& str);
    ~StringBad();

    StringBad& operator=(const StringBad& s);

    friend std::ostream& operator<<(std::ostream& os, const StringBad& st);

};