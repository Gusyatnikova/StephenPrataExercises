#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>

/*
int main() {
    std::cout << "SHRT max: " << SHRT_MAX << " Short min: " << SHRT_MIN << " bytes in short: " << sizeof(short) << std::endl;
    std::cout << "Int max: " << INT_MAX << " Int min: " << INT_MIN << " bytes in int: " << sizeof(int) << std::endl;
    std::cout << "Long max: " << LONG_MAX << " Long min: " << LONG_MIN << std::endl;

    int num = static_cast<int>(2'147'483'648);
    std::string num_str = std::to_string(num);
    std::sort(num_str.begin(), num_str.end(), std::greater<int>());
    num_str += " 1234";
    size_t delim;
    int greatest = std::stoi(num_str, &delim, 10);
    int second = std::stoi(&num_str[delim], nullptr, 10);
    std::cout << greatest << " " << second;
}
 */
//overloading of operators
/*
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

    Time operator+(const Time &rhs) const;

    Time operator-(const Time &rhs) const;

    Time operator*(double n) const;

    void Show() const;
};

int main() {
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total, diff, adjusted;

    std::cout << "weeding time = ";
    weeding.Show();
    std::cout << std::endl;

    std::cout << "waxing time = ";
    waxing.Show();
    std::cout << std::endl;

    std::cout << "total work time = ";
    total = weeding + waxing;
    total.Show();
    std::cout << std::endl;

    std::cout << "weeding - waxing time = ";
    diff = weeding - waxing;
    diff.Show();
    std::cout << std::endl;

    std::cout << "adjusted time = ";
    adjusted = total * 1.5;
    adjusted.Show();
    std::cout << std::endl;
    return 0;
}

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

Time Time::operator+(const Time &rhs) const {
    return Time(hours + rhs.hours, minutes + rhs.minutes);
}

void Time::Show() const {
    std::cout << hours << "h " << minutes << "m";
}

Time Time::operator-(const Time& rhs) const {
    Time diff;
    int tot1, tot2;
    tot1 = rhs.minutes + 60 * rhs.hours;
    tot2 = minutes + 60 * hours;
    diff.hours = (tot2 - tot1) / 60;
    diff.minutes = (tot2 - tot1) % 60;
    return diff;
}

Time Time::operator*(double n) const {
    long total_min = hours * n * 60 + minutes * n;
    return Time(total_min / 60, total_min % 60);
}
 */
//friends
/*
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

    Time operator+(const Time &rhs) const;

    //friend Time operator+(const Time& lhs, const Time& rhs);

    Time operator-(const Time &rhs) const;

    Time operator*(double n) const;

    friend Time operator*(double n, const Time& t);


    friend std::ostream& operator<<(std::ostream& os, const Time&t);

    void Show() const;
};

int main() {
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    std::cout << "Aida and Tosca:\n";
    std::cout << aida << "; " << tosca << std::endl;
    temp = aida + tosca;
    std::cout << "Aida + Tosca: " << temp << std::endl;
    temp = aida * 1.17;
    std::cout << "Aida * 1.17: " << temp << std::endl;
    std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl;
    return 0;
}

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

Time Time::operator+(const Time &rhs) const {
    return Time(hours + rhs.hours, minutes + rhs.minutes);
}

Time operator+(const Time& lhs, const Time& rhs) {
    return Time(lhs.hours + rhs.hours, lhs.minutes + rhs.minutes);
}

void Time::Show() const {
    std::cout << hours << "h " << minutes << "m";
}

Time Time::operator-(const Time& rhs) const {
    Time diff;
    int tot1, tot2;
    tot1 = rhs.minutes + 60 * rhs.hours;
    tot2 = minutes + 60 * hours;
    diff.hours = (tot2 - tot1) / 60;
    diff.minutes = (tot2 - tot1) % 60;
    return diff;
}

Time Time::operator*(double n) const {
    long total_min = hours * n * 60 + minutes * n;
    return Time(total_min / 60, total_min % 60);
}

Time operator*(double n, const Time& t) {
    return t * n;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
*/
