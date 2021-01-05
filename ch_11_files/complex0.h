#pragma once

#include <iostream>

class complex {
private:
    double real;
    double imaginary;
public:
    complex();
    complex(double, double);

    complex operator~() const;
    complex operator+(const complex& rhs) const;
    complex operator-(const complex& rhs) const;
    complex operator*(const complex& rhs) const;

    friend complex operator*(double num, const complex& comp);
    friend std::ostream& operator<<(std::ostream& os, const complex& comp);
    friend std::istream& operator>>(std::istream& os, complex& comp);
};