#include <iostream>
#include "sales.h"

namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        int i = 0;
        for (i = 0; i < QUARTERS && i < n; ++i) {
            s.sales[i] = ar[i];
        }
        for (int j = 0; j < QUARTERS - i; ++j) {
            s.sales[i + j] = 0;
        }
        if (i > 0) {
            s.max = s.min = s.average = s.sales[0];
            for (int i = 1; i < QUARTERS; ++i) {
                if (s.sales[i] < s.min) s.min = s.sales[i];
                if (s.sales[i] > s.max) s.max = s.sales[i];
                s.average += s.sales[i];
            }
            s.average /= 4;
        }
    }

    void setSales(Sales &s) {
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << "Enter sale " << i + 1 << std::endl;
            while (!(std::cin >> s.sales[i])) {
                std::cout << "Enter real number:\n";
                std::cin.clear();
                while (std::cin.get() != '\n') continue;
            }
        }
        s.max = s.min = s.average = s.sales[0];
        for (int i = 1; i < QUARTERS; ++i) {
            if (s.sales[i] < s.min) s.min = s.sales[i];
            if (s.sales[i] > s.max) s.max = s.sales[i];
            s.average += s.sales[i];
        }
        s.average /= 4;
    }

    void showSales(const Sales &s) {
        for (int i = 0; i < QUARTERS; ++i) {
            std::cout << s.sales[i] << " ";
        }
        std::cout << std::endl << "average: " << s.average
                  << " min: " << s.min << " max: " << s.max << std::endl;
    }
}