#pragma once

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    //Time operator+(const Time &rhs) const;
    //Time operator-(const Time &rhs) const;
    //Time operator*(double n) const;
    void Show() const;

    friend Time operator+(const Time& lhs, const Time& rhs);
    friend Time operator-(const Time& lhs, const Time& rhs);
    friend Time operator*(const Time& lhs, double n);
    friend Time operator*(double n, const Time& lhs);
};