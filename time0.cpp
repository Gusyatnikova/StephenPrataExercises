#include "time0.h"

Time::Time() { hours = minutes = 0; }

Time::Time(int h, int m) {
    hours = h;
    hours += m / 60;
    minutes = m % 60;
}

void Time::AddMin(int m) {
    //*this = Time(hours, minutes + m);
    hours += m / 60;
    minutes = m % 60;
}

void Time::AddHr(int h) {
    //*this = Time(hours + h, minutes);
    hours += h;
}

void Time::Reset(int h, int m) {
    //*this = Time(h, m);
    hours += h;
    hours += m / 60;
    minutes = m % 60;
}

void Time::Show() const {
    std::cout << hours << "h " << minutes << "m";
}

Time operator+(const Time& lhs, const Time& rhs) {
    return Time(lhs.hours + rhs.hours, lhs.minutes + rhs.minutes);
}

Time operator-(const Time& lhs, const Time& rhs) {
    Time diff;
    int tot1, tot2;
    tot1 = rhs.minutes + 60 * rhs.hours;
    tot2 = lhs.minutes + 60 * lhs.hours;
    diff.hours = (tot2 - tot1) / 60;
    diff.minutes = (tot2 - tot1) % 60;
    return diff;
}

Time operator*(const Time& lhs, double n) {
    long total_min = lhs.hours * n * 60 + lhs.minutes * n;
    return Time(total_min / 60, total_min % 60);
}

Time operator*(double n, const Time& lhs) {
    return operator*(lhs, n);
}
