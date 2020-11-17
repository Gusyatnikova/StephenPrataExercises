#include <iostream>
#include <climits>
#include <cfloat>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <iomanip>
#include <cctype>
#include <fstream>
//5 - 1
/*
int main() {
    int first, second;
    std::cin >> first >> second;
    int sum = 0;
    for (int i = first; i <= second; ++i) {
        sum += i;
    }
    std::cout << sum;
}
 */
//5 - 2
/*
int main() {
    const int size = 100;
    std::array<long double, size> factorials;
    factorials[0] = factorials[1] = 1.0L;
    for (int i = 2; i < size; ++i) {
        factorials[i] = i * factorials[i - 1];
    }
    std::cout << static_cast<long double>(factorials[size - 1]);
}
 */
//5 - 3
/*
int main() {
    double sum = 0;
    int cur;
    while(std::cin >> cur && cur != 0) {
        sum += cur;
        std::cout << sum << " ";
    }
}
 */
//5 - 4
/*
int main () {
   double dafna_start = 100.0, kleo_start = 100.0;
   double dafna_balance = dafna_start, kleo_balance = kleo_start;
    unsigned short year = 0;
    std::cout << std::setw(15) << "Dafna" << std::setw(10) << "Kleo\n";
    do {
        year++;
        dafna_balance += 0.1 * dafna_start;
        kleo_balance += 0.05 * kleo_balance;
        std::cout << std::left << std::setw(10) << year
                  << std::setw(10) << dafna_balance
                  << std::setw(10) <<  kleo_balance << std::endl;
   } while(dafna_balance > kleo_balance);
}
 */
//5 - 5, 5 - 6
/*
int main() {
    std::array<std::string, 12> months = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
    };
    std::array<std::array<double, 12>, 3> sales{0};
    std::array<double, 3> annually_sales{0};
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        int annual_sum = 0;
        for(int j = 0; j < months.size(); ++j) {
            std::cout << "Enter sales in " << months[j] << " of "
            << i + 1 << " year" << std::endl;
            std::cin >> sales[i][j];
            annual_sum += sales[i][j];
            sum += sales[i][j];
        }
        annually_sales[i] = annual_sum;
    }
    std::cout << "Sales by years:\n";
    std::cout << "First: " << annually_sales[0]
              << std::setw(10) << "Second: " << annually_sales[1]
              << std::setw(10) << "Third: " << annually_sales[2] << std::endl;
    std::cout << "Accumulated sales in year: " << sum;
}
 */
//5 - 7
/*
struct car {
    std::string model;
    int year;
};

int main() {
    int car_cnt;
    std::cout << "Count of cars in catalogue:\n";
    std::cin >> car_cnt;
    std::cin.get();
    car* car_catalogue = new car[car_cnt];
    for (int i = 0; i < car_cnt; ++i) {
        std::cout << "Car #" << i + 1 << ":" << std::endl;
        std::cout << "Enter car's model: \n";
        std::getline(std::cin, car_catalogue[i].model);
        std::cout << "Enter car's year: \n";
        std::cin >> car_catalogue[i].year;
        std::cin.get();
    }
    std::cout << "Here is your collection:\n";
    for (int i = 0; i < car_cnt; ++i) {
        std::cout << car_catalogue[i].year << " "
                  << car_catalogue[i].model << std::endl;
    }
    delete[] car_catalogue;
}
*/
//5 - 8
/*
int main() {
    char expected[5] = "done";
    int words_cnt = 0;
    char cur[20];
    do {
        std::cin >> cur;
        words_cnt++;
    } while(strcmp(expected, cur) != 0);
    std::cout << "You entered " << words_cnt - 1 << " words\n";
}
 */
//5 - 9
/*
int main() {
    std::string expected = "done";
    int words_cnt = 0;
    std::string cur;
    do {
        std::cin >> cur;
        words_cnt++;
    } while (cur != expected);
    std::cout << "You entered " << words_cnt - 1 << " words\n";
}
 */
//5 - 10

int main() {
    int rows_cnt;
    std::cout << "Enter count of rows: \n";
    std::cin >> rows_cnt;
    for (int i = 0; i < rows_cnt; ++i) {
        int k;
        for (k = 0; k < rows_cnt - i - 1; ++k) {
            std::cout << '.';
        }
        for(int l = 0; l < rows_cnt - k; ++l) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
