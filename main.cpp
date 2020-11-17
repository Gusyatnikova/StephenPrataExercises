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

//int main() {
/*
    std::cout << FLT_DIG << " " << FLT_MIN << " " << FLT_MAX << " " << FLT_MAX_10_EXP << std::endl;
    std::cout << DBL_DIG << " " << DBL_MIN << " " << DBL_MAX << " " << DBL_MAX_10_EXP;
    std::cout << "char bit: " << CHAR_BIT
              << " char min: " << CHAR_MIN
              << " char max: " << CHAR_MAX << "\n";
    std::cout << "short min: " << SHRT_MIN
              << " short max: " << SHRT_MAX << "\n";
    std::cout << "int min: " << INT_MIN
              << " int max: " << INT_MAX << "\n";
    std::cout << "long min: " << LONG_MIN
              << " long max: " << LONG_MAX << "\n";
    std::cout << "long long min: " << LLONG_MIN
              << " long long max: " << LLONG_MAX << "\n";
              */
/*    std::cout << "Enter the number of seconds:";
    long long sec;
    std::cin >> sec;
    short days = sec / (24 * 3600);
    short hours = (sec - (days * 24 * 3600)) / 3600;
    short min = (sec - (days * 24 * 3600) - (hours * 3600)) / 60;
    short seconds = sec - (days * 24 * 3600) - (hours * 3600) - (min * 60);
    std::cout << sec << " seconds = "
              << days << " "
              << hours << " "
              << min << " "
              << seconds << "\n";*/
/*
    long long earth_population;
    long long rus_population;
    std::cout << "Enter the world's population: \n";
    std::cin >> earth_population;
    std::cout << "Enter the Russia's population: \n";
    std::cin >> rus_population;
    std::cout << "The population of Russia is " << 100 * double(rus_population) / earth_population << "% of the world population.";*/

int main() {
    long double result = 1.1;
    int nums = 5, picks = 2;
    for (int n = nums, p = picks; p > 0; --n, --p) {
        result *= static_cast<double>(n) / p;
    }
    std::cout << result;
}