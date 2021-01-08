#pragma once
#include <string>

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string &fn = "Nullbody",
          long an = -1, double b = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    std::string Name() const { return fullName; }
    virtual void ViewAcct() const;
    virtual ~Brass();
};

class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &fn = "NullBody",
              long an = -1, double balance = 0.0,
              double ml = 500.0, double r = 0.11125);
    BrassPlus(const Brass &b, double ml = 500.0, double r = 0.11125);
    ~BrassPlus();
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};