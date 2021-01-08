#include <iostream>
#include <string>
//#include "brass.h"
#include "acctabc.h"

const int CLIENTS = 4;

//overriding
/*
int main() {
    std::cout.precision(4);
    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    std::cout << std::endl;
    Hoggy.ViewAcct();
    std::cout << std::endl;
    std::cout << "deposit $1000 into Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    std::cout << "NewBalance: $" << Hoggy.Balance() << std::endl;
    std::cout << "Withdraw $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.0);
    std::cout << "Pigg account balance: $" << Piggy.Balance() << std::endl;
    std::cout << "Withdraw 4200 $ from the Hogg account:\n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();
    return 0;
}*/
//using virtual
/*int main() {
    Brass* p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for (int i = 0; i < CLIENTS; ++i) {
        std::cout << "Enter client's name:\n";
        getline(std::cin, temp);
        std::cout << "Enter client's account number:\n";
        std::cin >> tempnum;
        std::cout << "Enter opening balance: $:";
        std::cin >> tempbal;
        std::cout << "Enter 1 for Brass account and 2 for BrassPlus account:\n";
        while (std::cin >> kind && (kind != '1' && kind != '2')) {
            std::cout << "Enter either 1 or 2:\n";
        }
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            std::cout << "Enter the overdraft limit: $\n";
            std::cin >> tmax;
            std::cout << "Enter the interest rate as a decimal fraction:\n";
            std::cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (std::cin.get() != '\n') continue;
    }
    std::cout << std::endl;
    for (int i = 0; i < CLIENTS; ++i) {
        p_clients[i]->ViewAcct();
        std::cout << std::endl;
    }
    for (int i = 0; i < CLIENTS; ++i) {
        delete p_clients[i];
    }
    std::cout << "Done.\n";
    return 0;
}*/
//using abstract base class
/*
int main() {
    AcctABC* p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for (int i = 0; i < CLIENTS; ++i) {
        std::cout << "Enter client's name:\n";
        getline(std::cin, temp);
        std::cout << "Enter client's account number:\n";
        std::cin >> tempnum;
        std::cout << "Enter opening balance: $:";
        std::cin >> tempbal;
        std::cout << "Enter 1 for Brass account and 2 for BrassPlus account:\n";
        while (std::cin >> kind && (kind != '1' && kind != '2')) {
            std::cout << "Enter either 1 or 2:\n";
        }
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            std::cout << "Enter the overdraft limit: $\n";
            std::cin >> tmax;
            std::cout << "Enter the interest rate as a decimal fraction:\n";
            std::cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (std::cin.get() != '\n') continue;
    }
    std::cout << std::endl;
    for (int i = 0; i < CLIENTS; ++i) {
        p_clients[i]->ViewAcct();
        std::cout << std::endl;
    }
    for (int i = 0; i < CLIENTS; ++i) {
        delete p_clients[i];
    }
    std::cout << "Done.\n";
    return 0;
}*/
