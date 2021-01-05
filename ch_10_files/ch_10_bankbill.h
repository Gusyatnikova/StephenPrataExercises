#pragma once
#include <iostream>
#include <string>

class BankBill {
public:
    BankBill();
    BankBill(const std::string&, const std::string&, int);
    void show() const;
    void add(int);
    bool take(int);
private:
    std::string fullname_;
    std::string bill_;
    int balance_;
};