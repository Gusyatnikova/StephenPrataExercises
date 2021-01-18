#include "studentc.h"
//composition usage (Student)
/*void Set(Student &sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {
    Student ada[pupils] = {
            Student(quizzes),
            Student(quizzes),
            Student(quizzes)
    };
    for (int i = 0; i < pupils; ++i) {
        Set(ada[i], quizzes);
    }
    std::cout << "\nStudent list:\n";
    for (int i = 0; i < pupils; ++i) {
        std::cout << ada[i].Name() << std::endl;
    }
    std::cout << "\nResults:\n";
    for (int i = 0; i < pupils; ++i) {
        std::cout << std::endl << ada[i];
        std::cout << "Average: " << ada[i].Average() << std::endl;
    }
    std::cout << "Done!\n";
    return 0;
}

void Set(Student &sa, int n) {
    std::cout << "Please enter the student's name: ";
    getline(std::cin, sa);
    std::cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; ++i) std::cin >> sa[i];
    while(std::cin.get() != '\n') continue;
}*/
// private inheritance usege (Student1)
/*
void Set(Student1 &sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {
    Student1 ada[pupils] = {
            Student1(quizzes),
            Student1(quizzes),
            Student1(quizzes)
    };
    for (int i = 0; i < pupils; ++i) {
        Set(ada[i], quizzes);
    }
    std::cout << "\nStudent list:\n";
    for (int i = 0; i < pupils; ++i) {
        std::cout << ada[i].Name() << std::endl;
    }
    std::cout << "\nResults:\n";
    for (int i = 0; i < pupils; ++i) {
        std::cout << std::endl << ada[i];
        std::cout << "Average: " << ada[i].Average() << std::endl;
    }
    std::cout << "Done!\n";
    return 0;
}

void Set(Student1 &sa, int n) {
    std::cout << "Please enter the student's name: ";
    getline(std::cin, sa);
    std::cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; ++i) std::cin >> sa[i];
    while(std::cin.get() != '\n') continue;
}*/
