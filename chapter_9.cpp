#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include "golf.h"
#include "sales.h"
//example of namespaces
/*
#include "chapter_9_namespaces.h"
void other();

void another();

int main() {
    using debts::Debt;
    using debts::showDebt;
    Debt golf = {
            {"Benny", "Goatsniff"},
            120.0
    };
    showDebt(golf);
    other();
    another();
    return 0;
}

void other() {
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for (i = 0; i < 3; ++i) {
        getDebt(zippy[i]);
    }
    for (i = 0; i < 3; ++i) {
        showDebt(zippy[i]);
    }
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}

void another() {
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}
 */
//9 - 1
/*
int main() {
    golf arr[4];
    int i;
    for (i = 0; i < 3 && setgolf(arr[i]); ++i) {}
    setgolf(arr[3], "Anny Bay", 12);
    for (int j = 0; j < i; ++j) {
        showgolf(arr[j]);
    }
    return 0;
}
 */
//9 - 2
/*
void strcount(const std::string &);
int main() {
    std::string input;
    std::cout << "Enter a line:\n";
    while (std::getline(std::cin, input)
           && !input.empty()) {
        strcount(input);
        std::cout << "Enter next line (empty line to quit):\n";
    }
    std::cout << "Bye!\n";
    return 0;
}

void strcount(const std::string &str) {
    static int total = 0;
    std::cout << "\"" << str << "\" contains ";
    total += str.size();
    std::cout << str.size() << " characters\n";
    std::cout << total << " characters total\n";
}
 */
//9 - 3
/*
struct chaff {
    char dross[20];
    int slag;
};
int main() {
    //option 1
    chaff buffer[3];
    chaff *p1 = new(buffer) chaff[3];
    std::strcpy(p1[0].dross, "aaaa");
    p1[0].slag = 1;
    std::strcpy(p1[1].dross, "bbbb");
    p1[1].slag = 2;
    std::strcpy(p1[2].dross, "cccc");
    p1[2].slag = 3;
    for (int i = 0; i < 3; ++i) {
        std::cout << p1[i].dross << " " << p1[i].slag << std::endl;
    }
    //option 2
    std::cout << "Option 2\n";
    chaff *buffer2 = new chaff[3];
    chaff *p2 = new(buffer2) chaff[3];
    std::strcpy(p2[0].dross, "aaaa");
    p2[0].slag = 1;
    std::strcpy(p2[1].dross, "bbbb");
    p2[1].slag = 2;
    std::strcpy(p2[2].dross, "cccc");
    p2[2].slag = 3;
    for (int i = 0; i < 3; ++i) {
        std::cout << p2[i].dross << " " << p2[i].slag << std::endl;
    }
    delete[] p2;
    return 0;
}
 */
//9 - 4
/*
int main() {
    using namespace SALES;
    Sales s1, s2, s3;
    const double arr1[QUARTERS] {1.1, 2.2, 3.3, 4.4};
    const double arr2[QUARTERS - 1] {11.1, 12.2, 13.3};
    setSales(s1, arr1, 4);
    setSales(s2, arr2, 2);
    setSales(s3);
    showSales(s1);
    showSales(s2);
    showSales(s3);
    return 0;
}
 */
