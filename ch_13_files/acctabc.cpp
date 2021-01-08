#include "acctabc.h"

//_________________AcctABC_________________//
AcctABC::AcctABC(const std::string &fn, long an, double bal)
        : fullName(fn), acctNum(an), balance(bal) {}

void AcctABC::Deposit(double amt) {
    if (amt < 0) {
        std::cout << "Negateve deposit not allowed."
                     " Deposit is cancelled.\n";
    } else {
        balance = amt;
    }
}

void AcctABC::Withdraw(double amt) {
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flag = std::cout.setf(
            std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = std::cout.precision(2);
    return f;
}

void AcctABC::Restore(AcctABC::Formatting &f) const {
    std::cout.setf(f.flag, std::ios_base::floatfield);
    std::cout.precision(f.pr);
}

//_________________Brass_________________//

void Brass::Withdraw(double amt) {
    if (amt < 0) {
        std::cout << "Withdraw amount must be positive."
                     " Withdraw cancelled.\n";
    } else if (amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        std::cout << "Withdraw amount of &" << amt
                  << " exceeds your balance.\n"
                     " Withdraw cancelled.\n";
    }
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    std::cout << "Brass Client: " << FullName() << std::endl;
    std::cout << "Account number: " << AcctNum() << std::endl;
    std::cout << "Balance: &" << Balance() << std::endl;
    Restore(f);
}

//_________________BrassPlus_________________//

BrassPlus::BrassPlus(const std::string &fn, long an,
                     double bal, double ml, double r)
        : AcctABC(fn, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &b, double ml, double r)
        : AcctABC(b) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();
    std::cout << "BrassPlus Client: " << FullName() << '\n';
    std::cout << "Account number: " << AcctNum() << '\n';
    std::cout << "Balance: $" << Balance() << '\n';
    std::cout << "Maximum Loan: $" << maxLoan << '\n';
    std::cout << "Owed to bank: $" << owesBank << '\n';
    std::cout.precision(3);
    std::cout << "Loan rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();
    double bal = Balance();
    if (amt <= bal) {
        AcctABC::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << '\n';
        std::cout << "Finance charge: $" << advance * rate << '\n';
        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else {
        std::cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    Restore(f);
}

