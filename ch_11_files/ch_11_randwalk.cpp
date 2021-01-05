#include <iostream>
#include <cstdlib>
#include <ctime>

#include "vect.h"

int main() {
    using VECTOR::Vector;
    std::srand(time(0));
    double direction = 0.0;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target = 0.0;
    double dstep = -1.1;
    std::cout << "Enter target distance (q to quit)\n";
    while(std::cin >> target) {
        std::cout << "Enter step length:\n";
        if (!(std::cin >> dstep)) break;
        while(result.magval() < target) {
            direction = std::rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
        }
        std::cout << "After " << steps << " steps, the subject "
                                          "has the following location:\n";
        std::cout << result << std::endl;
        result.polar_mode();
        std::cout << "re\n" << result << std::endl;
        std::cout << "Average outward distance per step = "
                  << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance (q to ruit):\n";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    while (std::cin.get() != '\n') continue;
    return 0;
}