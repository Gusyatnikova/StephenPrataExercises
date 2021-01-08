#include <iostream>
#include "brass.h"

using format = std::ios_base::fmtflags;
using precis = std::streamsize;

format setFormat();

void restore(format f, precis p);

//_____________________Brass____________________________//

Brass::Brass(const std::string &fn, long an, double b)
        : fullName(fn), acctNum(an), balance(b) {}

Brass::~Brass() {
    std::cout << "~Brass() for " << fullName << std::endl;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        std::cout << "Negative deposit not allowed."
                  << " Deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = std::cout.precision(2);
    if (amt < 0) {
        std::cout << "Withdraw amount must be positive."
                  << " Withdraw cancelled.\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        std::cout << "Withdraw amount: $" << amt
                  << " exceeds your balance.\n"
                  << "Withdraw cancelled.\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const { return balance; }

void Brass::ViewAcct() const {
    format initialState = setFormat();
    precis prec = std::cout.precision(2);
    std::cout << "Client: " << fullName << '\n'
              << "Account Number: " << acctNum << '\n'
              << "Balance: " << balance << '\n';
    restore(initialState, prec);
}

//___________________BrassPlus__________________________//

BrassPlus::BrassPlus(const std::string &fn, long an,
                     double b, double ml, double r)
        : Brass(fn, an, b), maxLoan(ml), rate(r), owesBank(0.0) {}

BrassPlus::BrassPlus(const Brass &b, double ml, double r)
        : Brass(b), maxLoan(ml), rate(r), owesBank(0) {}

BrassPlus::~BrassPlus() {
    std::cout << "~BrassPlus() for " << Brass::Name() << std::endl;
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precis prec = std::cout.precision(2);
    Brass::ViewAcct();
    std::cout << "Maximum loan: $" << maxLoan << '\n'
              << "Owed to bank: $" << owesBank << '\n';
    std::cout.precision(3);
    std::cout << "Loan Rate: $" << rate * 100 << "%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = std::cout.precision(2);
    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << '\n'
                  << "Financial charge: $" << advance * rate << '\n';
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        std::cout << "Credit limit excwwd. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

format setFormat() {
    return std::cout.setf(
            std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis s) {
    std::cout.setf(f);
    std::cout.precision(s);
}