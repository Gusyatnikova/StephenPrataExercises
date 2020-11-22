#include "ch_10_bankbill.h"

BankBill::BankBill() {
    fullname_ = "empty";
    bill_ = "empty";
    balance_ = 0;
}

BankBill::BankBill(const std::string &name,
                   const std::string &bill, int balance) {
    fullname_ = name;
    bill_ = bill;
    balance_ = balance;
}

void BankBill::show() const {
    std::cout << "bank bill of " << fullname_
              << " #" << bill_
              << " has $" << balance_ << std::endl;
}

void BankBill::add(int sum) {
    balance_ += sum;
}

bool BankBill::take(int sum) {
    if (sum > balance_) {
        std::cout << "Not enough money to take from bill #" << bill_
                  <<  ". Operation have been terminated.\n";
        return false;
    }
    balance_ -= sum;
    return true;
}
