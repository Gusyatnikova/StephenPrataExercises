#pragma once

#include <string>
#include <valarray>
#include <iostream>

//composition usage
class Student {
private:
    //can use only inside class and friends
    using ArrayDb = std::valarray<double>;
    std::string name;
    ArrayDb scores;

    std::ostream &arr_out(std::ostream &os) const;

public:
    Student() : name("Null Student"), scores() {}
    explicit Student(const std::string &s) : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}
    Student(const std::string &str, int n) : name(str), scores(n) {}
    Student(const std::string &str, const ArrayDb &arr)
            : name(str), scores(arr) {}
    Student(const char *str, const double *pd, int n)
            : name(str), scores(pd, n) {}
    ~Student() {}

    double Average() const;
    const std::string &Name() const { return name; }
    double &operator[](int i) { return scores[i]; }
    double operator[](int i) const { return scores[i]; }

    friend std::istream &operator>>(std::istream &is, Student &student);
    friend std::istream &getline(std::istream &is, Student &student);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};

//private inheritance usage
class Student1 : private std::string, private std::valarray<double> {
private:
    //have 2 implicit inherited nonnamed objects
    using ArrayDb = std::valarray<double>;
    std::ostream &arr_out(std::ostream &os) const;
public:
    Student1(const char *str, const double *pd, int n)
            : std::string(str), ArrayDb(pd, n) {}
    //use ClassName(val) instead fieldName(val)
    Student1() : std::string("Null Student") {}
    explicit Student1(const std::string &s) : std::string(s) {}
    explicit Student1(int n) : std::string("Nully"), ArrayDb(n) {}
    Student1(const std::string &str, int n) : std::string(str), ArrayDb(n) {}
    Student1(const std::string &str, const ArrayDb &arr)
            : std::string(str), ArrayDb(arr) {}
    ~Student1() {}
    double Average() const;
    const std::string &Name() const;
    double &operator[](int i);
    double operator[](int i) const;

    friend std::istream &operator>>(std::istream &is, Student1 &student);
    friend std::istream &getline(std::istream &is, Student1 &student);
    friend std::ostream &operator<<(std::ostream &os, const Student1 &student);
};