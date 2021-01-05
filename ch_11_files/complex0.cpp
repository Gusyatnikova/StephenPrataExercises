#include "complex0.h"

complex::complex() {
    real = imaginary = 0;
}

complex::complex(double r, double i) {
    real = r;
    imaginary = i;
}

complex complex::operator~() const {
    return complex(real, -1 * imaginary);
}

complex complex::operator+(const complex &rhs) const {
    return complex(real + rhs.real, imaginary + rhs.imaginary);
}

complex complex::operator-(const complex &rhs) const {
    return complex(real - rhs.real, imaginary - rhs.imaginary);
}

complex complex::operator*(const complex &rhs) const {
    return complex((real * rhs.real) - (imaginary * rhs.imaginary),
                   (real * rhs.imaginary) + (imaginary * rhs.real));
}

complex operator*(double num, const complex& comp) {
    return complex(num * comp.real, num * comp.imaginary);
}

std::ostream& operator<<(std::ostream& os, const complex& comp) {
    os << "(" << comp.real << "," << comp.imaginary << "i)";
    return os;
}

std::istream& operator>>(std::istream& is, complex& comp) {
    std::cout << "real:";
    std::string r;
    is >> r;
    if ('q' == r[0]) {
        is.setstate(std::ios::failbit);
        return is;
    }
    comp.real = std::stod(r);
    std::cout << "imaginary:";
    is >> comp.imaginary;
    return is;
}
