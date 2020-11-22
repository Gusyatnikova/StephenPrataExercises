#include <iostream>
#include <string>
#include <cstring>
#include "ch_10_bankbill.h"
#include "ch_10_person.h"
#include "ch_10_sales.h"
#include "ch_10_list.h"
/*
class MyClass {
public:
    MyClass() {
        member_ = -1;
        mute = member_ * 1.1;
        std::cout << "MyClass " << member_ << " constr\n";
    }
    MyClass(int num) {
        member_ = num;
        mute = num * 1.1;
        std::cout << "MyClass " << member_ << " constr\n";
    }
    ~MyClass() {
        std::cout << "MyClass " << member_ << " destr\n";
    }
    void show() const {
        std::cout << "member: " << member_ << "\n";
        mute = member_ * 11.1; //!! because mute declared as mutable
        std::cout << "mute: " << mute << "\n";
    }
private:
    int member_;
    mutable double mute;
    const int arr_size = 3;
};

MyClass global(100);

namespace example {
    static MyClass in_namespace(10);
}

int main() {
    enum egg : short {Small, Medium, Large, Jumbo};
    enum class t_shirt {Small, Medium, Large, XLarge};

    MyClass a; // default constr called
    a = MyClass(-3); //constr for temp obj, destr for tmp obj
    {
        std::cout << "inner block\n";
        int a = 4;
        int b = 7;
        std::cout << "before MyClass c\n";
        MyClass c(1);
        std::cout << "after MyClass c\n";
    }
    MyClass* ptr = new MyClass(2);
    MyClass* ptr1 = ptr;
    ptr = nullptr;
    delete ptr1;

    const MyClass one {3};
    one.show();
    t_shirt rolf = t_shirt::Small;
    int rolf_int = static_cast<int>(rolf);
    int on_egg = Small;
    return 0;
}
*/
//10 - 1
/*
int main() {
    BankBill family[4];
    for (int i = 0; i < 3; ++i) {
        std::string name, bill;
        int sum;
        std::cout << "Enter name:\n";
        std::getline(std::cin, name);
        std::cout << "Enter num of bill:\n";
        std::getline(std::cin, bill);
        std::cout << "Enter balance of bill:\n";
        std::cin >> sum;
        std::cin.get();
        family[i] = {name, bill, sum};
    }
    std::cout << "Before changes:\n";
    for (const auto& it : family) {
        it.show();
    }
    std::cout << "After changes:\n";
    family[0].add(10000);
    family[0].show();
    family[1].take(100'000);
    family[2].show();
    return 0;
}
 */
//10 - 2
/*
int main() {
    Person one;
    Person two("Smiththecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
    return 0;
}
 */
//10 - 3
/*
const int Len = 40;
class Golf {
private:
    char fullname_[Len];
    int handicap_;
public:
    Golf() {fullname_[0] = '\0'; handicap_ = 0;}
    Golf(const char* name, int hc){strcpy(fullname_, name); handicap_ = hc;}
    void setgolf () {
        std::string name = "";
        int handicap = 0;
        std::cout << "Enter a name:\n";
        while (!std::getline(std::cin, name)) {
            std::cout << "Enter correct name:\n";
            while(std::cin.get() != '\n') continue;
        }
        if (name[0] != '\0') {
            std::cout << "Enter a handicap:\n";
            while (!(std::cin >> handicap)) {
                std::cout << "Enter integer value of handicap:\n";
                while (std::cin.get() != '\n') continue;
            }
            std::cin.get();
        }
        strcpy(this->fullname_, name.c_str());
        this->handicap_ = handicap;
    }
    void handicap (int hc) {
        handicap_ = hc;
    }
    void showgolf() const {
        std::cout << fullname_ << " have hc: " << handicap_ << std::endl;
    }
};
int main() {
    Golf arr[4] {
            {"Marco Nonilli", 30},
            {"Pedro Poputto", 12}
    };
    std::cout << "before setgolf\n";
    for (const auto& it : arr) {
        it.showgolf();
    }
    arr[2].setgolf();
    arr[3].setgolf();
    arr[3].handicap(3'000);
    std::cout << "after setgolf && handicap\n";
    for (const auto& it : arr) {
        it.showgolf();
    }
    return 0;
}
 */
//10 - 4
/*
int main() {
    using namespace SALES;
    const double arr1[QUARTERS]{1.1, 2.2, 3.3, 4.4};
    const double arr2[QUARTERS - 1]{11.1, 12.2, 13.3};
    Sales s1(arr1, 4);
    Sales s2(arr2, 2);
    Sales s3;
    s3.setSales();
    s1.showSales();
    s2.showSales();
    s3.showSales();
    return 0;
}
 */
//10 - 5
/*
struct customer {
    char fullname[35];
    double payment;
};
using Item = customer;

class Stack {
private:
    static const int MAX = 5;
    Item stack[MAX];
    int top;
public:
    Stack() {top = 0;}
    bool push(const Item& it) {
        if (top < MAX) {
            stack[top++] = it;
            return true;
        } else {
            std::cout << "Stack overflow. Operation was terminated.\n";
            return false;
        }
    }
    bool pop(Item& item) {
        if (top == 0) {
            std::cout << "Stack is empty. Operation was terminated.\n";
            return false;
        }
        item = stack[--top];
        return true;
    }
    bool isEmpty() const {
        return top == 0;
    }
    bool isFull() const {
        return top == MAX;
    }
};

int main() {
    int report = 0;
    Stack department;
    bool success;
    Item first = {"Natalya Gusyatnikova", 1000};
    const Item second = {"Nata Gus", 2000};
    success = department.push(first);
    success = department.push(second);
    Item last;
    success = department.pop(last);
    report += last.payment;
    success = department.pop(last);
    report += last.payment;
    std::cout << "report: " << report << std::endl;
    success = department.pop(last);
    return 0;
}
 */
//10 - 6
/*
class Move {
public:
    Move(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
    void showmove() const {
        std::cout << "x = " << x << " y = " << y << std::endl;
    }
    Move add(const Move& m) const {
        //add - method of Move class -> it have access to private fields of m object
        return Move(x + m.x, y + m.y);
    }
    void reset(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
private:
    double x;
    double y;
};

int main() {
    Move m1(1.1, -2.2);
    m1.showmove();
    m1.reset(11.1, -15.1);
    m1.showmove();
    Move m2 = {-20.45, 50.0005};
    Move m3 = m1.add(m2);
    m3.showmove();
    return 0;
}
 */
//10 - 7
/*
class Plorg {
private:
    const static int MAX_NAME_LEN = 20;
    char name[20];
    int CI;
public:
    Plorg() {
        strcpy(name, "Plorga");
        CI = 50;
    }
    Plorg(const char* n, int ci) {
        strcpy(name, n);
        CI = ci;
    }
    void setCI(int ci) {CI = ci;}
    void present() {
        std::cout << "Plorg " << name << " have CI: " << CI << std::endl;
    }
};

int main() {
    Plorg pl1;
    pl1.present();
    pl1.setCI(-40);
    pl1.present();
    Plorg pl2 {"Natasna", 100};
    pl2.present();
    return 0;
}
 */
//10 - 8
/*
void add(Item& it) {
    it += 111.111;
}
void print(Item& it) {
    std::cout << it << " ";
}

int main() {
    List list;
    Item it1 = 0.0, it2 = 1.1, it3 = -1.1, it4 = 5.5, it5 = -5.5, it6 = 10.1;
    list.push(it1);
    list.push(it2);
    list.visit(print);
    std::cout << std::endl;
    list.visit(add);
    list.visit(print);
    std::cout << std::endl;
    if (!list.full()) {
        list.push(it3);
        list.push(it4);
    }
    if (!list.empty()) {
        list.visit(print);
    }
    return 0;
}
 */