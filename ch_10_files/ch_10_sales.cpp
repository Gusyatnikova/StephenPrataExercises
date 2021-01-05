#include "ch_10_sales.h"
#include <iostream>

SALES::Sales::Sales() = default;
SALES::Sales::Sales(const double ar[], int n) {
    int i = 0;
    for (i = 0; i < QUARTERS && i < n; ++i) {
        sales[i] = ar[i];
    }
    for (int j = 0; j < QUARTERS - i; ++j) {
        sales[i + j] = 0;
    }
    if (i > 0) {
        max = min = average = sales[0];
        for (int i = 1; i < QUARTERS; ++i) {
            if (sales[i] < min) min = sales[i];
            if (sales[i] > max) max = sales[i];
            average += sales[i];
        }
        average /= 4;
    }
}
void SALES::Sales::showSales() const {
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << sales[i] << " ";
    }
    std::cout << std::endl << "average: " << average
              << " min: " << min << " max: " << max << std::endl;
}

void SALES::Sales::setSales() {
    double input[QUARTERS];
    for (int i = 0; i < QUARTERS; ++i) {
        std::cout << "Enter sale " << i + 1 << std::endl;
        while (!(std::cin >> input[i])) {
            std::cout << "Enter real number:\n";
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
        }
    }
    *this = Sales(input, QUARTERS);
}




