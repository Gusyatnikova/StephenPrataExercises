#include <iostream>
inline void foo(int a) {
    std::cout << "int a\n";
}
inline void foo1(int a) {
    std::cout << "int a\n";
}



int main() {
    int x = 12;
    int y = 100;
    std::cout << "In main " << "y: " << y << " &y: " << &y << std::endl;
    {
        std::cout << "x: " << x << " &x: " << &x << std::endl;
        int x = 0;
        std::cout << "x: " << x << " &x: " << &x << "\n"
        << "y: " << y << " &y: " << &y << std::endl;
    }
    std::cout << "x: " << x << " &x: " << &x << std::endl;

    {
        void show() {
            std::cout << "In show()\n";
        }
        show();
    }
    show();
    return 0;
}