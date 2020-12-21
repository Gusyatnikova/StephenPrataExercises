#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>
#include <deque>
#include <time.h>
#include "vect.h"
#include "time0.h"
#include "stonewt.h"
#include "complex0.h"
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
//11 - 1
/*
using Path = std::deque<std::pair<double, double>>;
VECTOR::Vector process_path(Path& path, double target, double dstep)
{
    using VECTOR::Vector;
    std::srand(time(0));
    double direction = 0.0;
    Vector step;
    Vector result(0.0, 0.0);
    std::ofstream report("randomWalkLog.txt");
    if (!report.is_open()) {
        throw std::runtime_error("cannot open log file");
    }
    report << "Target Distance: " << target << ", Step Size: " << dstep << "\n";
    long i = 0;
    while (result.magval() < target) {
        auto test = result.magval();
        if (test > 90) {
            bool test_stop = true;
        }
        direction = std::rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        report << i << ": " << "(x,y) = (" << result.xval()
               << ", " << result.yval() << ")\n";
        result = result + step;
        path.push_back(std::make_pair(result.xval(), result.yval()));
        ++i;
    }
    report << "After " << i << " steps, the subject has the following location:\n"
           << result;
    report.close();
    return result;
}

int main() {
    double target = 197.4;
    double dstep = 11.32;
    Path path;
    process_path(path, target, dstep);
    return 0;
}
 */
//11 - 2
/*
using Path = std::deque<std::pair<double, double>>;
VECTOR::Vector process_path(Path& path, double target, double dstep)
{
    using VECTOR::Vector;
    std::srand(time(0));
    double direction = 0.0;
    Vector step;
    Vector result(0.0, 0.0);
    std::ofstream report("randomWalkLog.txt");
    if (!report.is_open()) {
        throw std::runtime_error("cannot open log file");
    }
    report << "Target Distance: " << target << ", Step Size: " << dstep << "\n";
    long i = 0;
    while (result.magval() < target) {
        auto test = result.magval();
        if (test > 90) {
            bool test_stop = true;
        }
        direction = std::rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        report << i << ": " << "(x,y) = (" << result.xval()
               << ", " << result.yval() << ")\n";
        result = result + step;
        path.push_back(std::make_pair(result.xval(), result.yval()));
        ++i;
    }
    report << "After " << i << " steps, the subject has the following location:\n"
           << result;
    report.close();
    return result;
}
//test: public interface haven't changed
int main() {
    double target = 197.4;
    double dstep = 11.32;
    Path path;
    process_path(path, target, dstep);
    return 0;
}
*/
//11 - 3
/*
using Path = std::deque<std::pair<double, double>>;
VECTOR::Vector process_path(Path &path, double target, double dstep) {
    using VECTOR::Vector;
    std::srand(time(0));
    double direction = 0.0;
    Vector step;
    Vector result(0.0, 0.0);
    std::ofstream report("randomWalkLog.txt");
    if (!report.is_open()) {
        throw std::runtime_error("cannot open log file");
    }
    report << "Target Distance: " << target << ", Step Size: " << dstep << "\n";
    long i = 0;
    while (result.magval() < target) {
        auto test = result.magval();
        if (test > 90) {
            bool test_stop = true;
        }
        direction = std::rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        report << i << ": " << "(x,y) = (" << result.xval()
               << ", " << result.yval() << ")\n";
        result = result + step;
        path.push_back(std::make_pair(result.xval(), result.yval()));
        ++i;
    }
    report << "After " << i << " steps, the subject has the following location:\n"
           << result;
    report.close();
    return result;
}

int main() {
    double target = 0.0;
    double dstep = 0.0;
    long n = 0;
    std::cout << "Enter distance to walk, length of step and number of attempts:\n";
    std::cin >> target >> dstep >> n;
    Path path;
    long max_steps_cnt = 0;
    long min_steps_cnt = LONG_MAX;
    long i = n;
    long long total_steps_cnt = 0;
    while (i--) {
        process_path(path, target, dstep);
        total_steps_cnt += path.size();
        if (path.size() < min_steps_cnt) min_steps_cnt = path.size();
        if (path.size() > max_steps_cnt) max_steps_cnt = path.size();
        path.clear();
    }
    std::cout << "Maximum numbers of step: " << max_steps_cnt << "\n"
              << "Minimum numbers of step: " << min_steps_cnt << "\n"
              << "Average numbers of step: " << total_steps_cnt / n << "\n";
    return 0;
}
*/
//11 - 4 (time.h and time.cpp)
/*
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

    std::cout << "adjusted time(2) = ";
    adjusted = 1.5 * total;
    adjusted.Show();
    std::cout << std::endl;
    return 0;
}
 */
//11 - 5
/*
void display(const Stonewt& st, int n);

int main() {
    Stonewt incognito = Stonewt(275);
    Stonewt wolf(285.7, Stonewt::FLOAT_POUNDS);
    Stonewt taft(21, Stonewt::POUNDS);
    std::cout << "the celebrity weighed ";
    //incognito.show_stn();
    std::cout << incognito;
    std::cout << "the detective weighed ";
    //wolf.show_stn();
    std::cout << wolf;
    std::cout << "the President weighed ";
    //taft.show_lbs();
    std::cout << taft;
    incognito = Stonewt(276.8);
    taft = Stonewt(325, Stonewt::POUNDS);
    std::cout << "After dinner, the celebrity weighed ";
    std::cout << incognito;
    //incognito.show_stn();
    std::cout << "After dinner, the President weighed ";
    std::cout << taft;
    //taft.show_lbs();
    std::cout << "Check +: stone + pounds, float pounds + stone\n";
    std::cout << incognito + taft;
    std::cout << wolf + incognito;
    std::cout << "Check -: stone - pounds, float pounds - pounds\n";
    std::cout << incognito - taft;
    std::cout << wolf - taft;
    std::cout << "Check stonewt * stonewt, stonewt * num, num * stonewt:\n";
    std::cout << incognito * taft;
    std::cout << taft * 2.0;
    std::cout << wolf * 2.5;
    std::cout << "Check num * stonewt: stone, pounds, float pounds\n";
    std::cout << 2 * incognito;
    std::cout << 2 * taft;
    std::cout << 2 * wolf;
    display(taft, 2);
    std::cout << "The wrestler weighed even more.\n";
    display(Stonewt(422), 2);
    std::cout << "No stone left unearned\n";

    return 0;
}

void display(const Stonewt& st, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Wow! ";
        std::cout << st;
    }
}*/
//11 - 6
/*

int main() {
    const int size_array = 6;
    Stonewt arr[size_array] = {
            Stonewt(111.1, Stonewt::STONE),
            Stonewt(11.11, Stonewt::POUNDS),
            Stonewt(1.111, Stonewt::FLOAT_POUNDS)
    };
    int values_cnt = 3;
    double num;
    for (int i = 0; i < values_cnt; ++i) {
        std::cout << "enter " << i + 1 << " value:\n";
        std::cin >> num;
        arr[size_array - values_cnt + i] = Stonewt(num);
    }
    Stonewt max = Stonewt(0);
    Stonewt min = Stonewt(INT_MAX / 2);
    Stonewt eleven = Stonewt(11);
    int more_than_eleven = 0;
    for (int i = 0; i < size_array; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] >= eleven) ++more_than_eleven;
    }
    std::cout << "Max: " << max << "\n"
              << "Min: " << min << "\n"
              << "More than 11: " << more_than_eleven << "\n";
    return 0;
}
*/
//11 - 7
/*

int main() {
    complex a(3.0, 4.0);
    complex c;
    std::cout << "Enter a complex number (q to quit):\n";
    while (std::cin >> c) {
        std::cout << "c is " << c << "\n";
        std::cout << "complex conjugate is " << ~c << "\n";
        std::cout << "a is " << a <<  '\n';
        std::cout << "a + c is " << a + c << '\n';
        std::cout << "a - c is " << a - c << '\n';
        std::cout << "a * c is " << a * c << '\n';
        std::cout << "2 * c is " << 2 * c << '\n';
        std::cout << "Enter a complex number (q to quit):\n";
    }
    std::cout << "Done!\n";
    return 0;
}*/
