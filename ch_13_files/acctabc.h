#pragma once

#include <iostream>
#include <cstring>

class AcctABC {
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string &FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting &f) const;

public:
    AcctABC(const std::string &fn = "Nullbody",
            long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt = 0) = 0;
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0;
    virtual ~AcctABC() {}
};

class Brass : public AcctABC {
public:
    Brass(const std::string &fn = "Nullbody",
          long an = -1, double bal = 0.0)
          : AcctABC(fn, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

class BrassPlus : public AcctABC {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &fn = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500.0, double r = 0.1);
    BrassPlus (const Brass &b, double ml, double r);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes(double ob) { owesBank = ob; }
};