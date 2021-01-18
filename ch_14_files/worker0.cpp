#include <iostream>
#include "worker0.h"

//__________Worker__________//

void Worker::Data() const {
    std::cout << "Name: " << fullname << '\n'
              << "Employee ID: " << id << '\n';
}

void Worker::Get() {
    getline(std::cin, fullname);
    std::cout << "Enter worker's id: ";
    std::cin >> id;
    while(std::cin.get() != '\n') continue;
}

Worker::~Worker() {}

void Worker::Set() {
    std::cout << "Enter worker's name: ";

}

void Worker::Show() const {

}

//__________Waiter__________//

void Waiter::Set() {
    std::cout << "Enter worker's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const {
    std::cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const {
    std::cout << "Panache rating: " << panache << '\n';
}

void Waiter::Get() {
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while(std::cin.get() != '\n') continue;
}

//__________Singer__________//

void Singer::Get() {
    std::cout << "Enter number for singer's vocal range:\n";
    int i;
    for(i = 0; i < Vtypes; ++i) {
        std::cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3) std::cout << std::endl;
    }
    if (i % 4 != 0) std::cout << std::endl;
    while(std::cin >> voice && (voice < 0 || voice >= Vtypes))
        std::cout << "Please enter a value >= 0 and < " << Vtypes << '\n';
    while(std::cin.get() != '\n') continue;
}

char * Singer::pv[] = {
        "other", "alto", "contralto", "soprano", "bass", "baritone", "tenoir"};

void Singer::Set() {
    std::cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    std::cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const {
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}

//__________SingingWaiter__________//

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get() {
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Set() {
    std::cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const {
    std::cout << "Category: singing waiter:\n";
    Worker::Data();
    Data();
}