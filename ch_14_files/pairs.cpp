#include <iostream>
#include <string>
#include "stacktp.h"

/*

#include <typeinfo>

template<typename T1, typename T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    Pair() {}

    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}

    T1 &first();

    T2 &second();

    T1 first() const;

    T2 second() const;

    template<typename T3>
    T3 foo(T3 tmp) const { return tmp;}
};

template<typename T1, typename T2>
T1 &Pair<T1, T2>::first() { return a; }

template<typename T1, typename T2>
T2 &Pair<T1, T2>::second() { return b; }

template<typename T1, typename T2>
T1 Pair<T1, T2>::first() const { return a; }

template<typename T1, typename T2>
T2 Pair<T1, T2>::second() const { return b; }

template <typename T = float>
T foo(T a = 1) {return a;}

int main() {
    //std::cout << typeid(p.foo(34)).name() << std::endl;
    //std::cout << typeid(foo()).name() << "___" << typeid(foo(3.0)).name() << '\n';
    Pair<std::string, int> ratings[4] = {
            Pair<std::string, int>("The Purpled Duck", 5),
            Pair<std::string, int>("Jadiquie's Frisco Al Fresco", 4),
            Pair<std::string, int>("Cafe Souffle", 5),
            Pair<std::string, int>("Bertie's Eats", 3)
    };
    //typename is Pair<std::string, int>/ Not the Pair
    int joints = sizeof(ratings) / sizeof(Pair<std::string, int>);
    std::cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; ++i) {
        std::cout << ratings[i].second() << ":\t"
                  << ratings[i].first() << std::endl;
    }
    std::cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Berie's Fab Eats";
    ratings[3].second() = 6;
    std::cout << ratings[3].second() << ":\t"
              << ratings[3].first() << '\n';
    return 0;
}*/

/*template<template<typename T> class Thing>
class Crab {
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() {}

    bool push(int a, double x) { return s1.push(a) && s2.push(x); }

    bool pop(int &a, double &x) { return s1.pop(a) && s2.pop(x); }
};

int main() {
    Crab<Stack> nebula;
    int ni;
    double nb;
    std::cout << "Enter int double pairs, such as 4 3.5 (0 0 to end)\n";
    while (std::cin >> ni >> nb && ni > 0 && nb > 0) {
        if (!nebula.push(ni, nb)) break;
    }
    while (nebula.pop(ni, nb)) std::cout << ni << ", " << nb << '\n';
    std::cout << "Done!\n";
    return 0;
}*/

//template friends for template class

//templates prototypes:
/*
template <typename T> void counts();
template <typename T> void report(T&);

template<typename TT>
class HasFriendT {
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT &i) : item(i) {++ct;}
    ~HasFriendT(){--ct;}
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT>&);
};

template<typename T>
//type variableName = value;
int HasFriendT<T>::ct = 0;

template <typename T>
void counts() {
    std::cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    std::cout << "template counts(): " << HasFriendT<T>::ct << std::endl;
}

template <typename T>
void report(T & hf) {
    std::cout << hf.item << std::endl;
}

int main() {
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);
    report(hfi2);
    report(hfdb);
    std::cout << "counts<int>() output:\n";
    counts<int>();
    std::cout << "counts<double>() output:\n";
    counts<double>();
    return 0;
}
*/
