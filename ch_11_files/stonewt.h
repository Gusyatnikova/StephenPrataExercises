#pragma once
#include <iostream>

class Stonewt {
public:
    enum Mode{STONE, POUNDS, FLOAT_POUNDS};
private:
    enum {Lbs_per_stn = 14};
    long stone;
    double pds_left;
    long pounds;
    Mode mode;
public:
    explicit Stonewt(double value, Mode form = STONE);
    //Stonewt(int stn, double lbs, Mode form = STONE);
    Stonewt();
    ~Stonewt();
    Stonewt operator+(const Stonewt& rhs) const;
    Stonewt operator-(const Stonewt& rhs) const;
    Stonewt operator*(const Stonewt& rhs) const;
    bool operator<(const Stonewt& rhs) const;
    bool operator>(const Stonewt& rhs) const;
    bool operator==(const Stonewt& rhs) const;
    bool operator!=(const Stonewt& rhs) const;
    bool operator <=(const Stonewt& rhs) const;
    bool operator>=(const Stonewt& rhs) const;
    //void show_lbs() const;
    //void show_stn() const;
    friend Stonewt operator*(double num, const Stonewt& st);
    friend Stonewt operator*(const Stonewt& st, double num);
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);

};