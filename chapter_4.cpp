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

//4 - 1
/*
    std::cout << "What is your first name?";
    std::string first_name;
    //std::getline(std::cin, first_name);
    //std::cin >> first_name >> std::ws >> first_name1;
    std::cout << "What is your last name?";
    std::string last_name;
    //std::cin >> last_name;
    std::getline(std::cin, last_name);
    std::cout << "What letter grade do you deserve?";
    char grade;
    std::cin >> grade;
    std::cout << "What is your age?";
    unsigned int age;
    std::cin >> age;
    std::cout << "Name: " << last_name << ", " << first_name << std::endl
              << "Grade: " << ++grade << std::endl
              << "Age: " << age;
              */
//4 - 2
/*
std::string name, dessert;
std::cout << "Enter your name:\n";
std::getline(std::cin, name);
std::cout << "Enter your favourite dessert:\n";
std::getline(std::cin, dessert);
std::cout << "I have some delicious " << dessert
          << " for you, " << name << ".\n";
*/
//4 - 3
/*
    char first_name[20];
    char last_name[20];
    std::cout << "Enter your first name:";
    std::cin >> first_name;
    std::cout << "Enter your last name:";
    std::cin >> last_name;
    char name[30];
    strcpy(name, last_name);
    strcat(name, ", ");
    strcat(name, first_name);
    std::cout << name;
    */
//4 - 4
/*
    std::string first_name, last_name;
    std::cout << "Enter your first name:";
    std::cin >> first_name;
    std::cout << "Enter your last name:";
    std::cin >> last_name;
    std::string name = last_name + ", " + first_name;
    std::cout << "Your name: " << name;
*/
//4 - 5
/*
    struct CandyBar {
        std::string name;
        double weight;
        unsigned int ccal;
    };
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    std::cout << "Name: " << snack.name
              << "\nWeight: " << snack.weight
              << "\nCcal: " << snack.ccal;
*/
//4 - 6
/*
    struct CandyBar {
        std::string name;
        double weight;
        unsigned int ccal;
    };
    CandyBar arr[3] = {
            {"a", 2.2, 12},
            {"b", 3.3, 13},
            {"c", 4.4, 14}
    };

    for (int i = 0; i < 3; i++) {
        std::cout << arr[i].name << " "
                  << arr[i].weight << " "
                  << arr[i].ccal << std::endl;
    }
*/
//4 - 7
/*
struct Pizza
{
    std::string producer;
    double diameter;
    double weight;
};
Pizza pizza;
std::cout << "Enter producer:";
std::getline(std::cin, pizza.producer);
std::cout << "Enter diameter:";
std::cin >> pizza.diameter;
std::cout << "Enter weight:";
std::cin >> pizza.weight;
std::cout << "Producer: " << pizza.producer
          << "\nDiameter: " << pizza.diameter
          << "\nWeight: " << pizza.weight << "\n";
*/
//4 - 8
/*
    struct Pizza
    {
        std::string producer;
        double diameter;
        double weight;
    };
    Pizza* pizza = new Pizza;
    std::cout << "Enter diameter:";
    (std::cin >> pizza->diameter).get();
    std::cout << "Enter producer:";
    std::getline(std::cin, pizza->producer);
    std::cout << "Enter weight:";
    std::cin >> pizza->weight;
    std::cout << "Producer: " << pizza->producer
              << "\nDiameter: " << pizza->diameter
              << "\nWeight: " << pizza->weight << "\n";
              delete pizza;
*/
//4 - 9
/*
    struct CandyBar {
        std::string name;
        double weight;
        unsigned int ccal;
    };
    CandyBar* arr = new CandyBar[3] {
            {"a", 2.2, 12},
            {"b", 3.3, 13},
            {"c", 4.4, 14}
    };
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i].name << " "
                  << arr[i].weight << " "
                  << arr[i].ccal << std::endl;
    }
delete[] arr;
 */
//4 - 10
/*
std::array<double, 3> results;
std::cout << "Enter 3 results:";
std::cin >> results[0] >> results[1] >> results[2];
std::cout << "Middle is: " << (results[0] + results[1] + results[2]) / 3;
*/

int main() {

}