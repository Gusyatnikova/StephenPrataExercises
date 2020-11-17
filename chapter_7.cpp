#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <cstring>

//alias usage for declaration pointer to function
/*
double foo(int*, float);
using p_foo = double(*)(int*, float);

double foo(int* arr, float num) {
    return num;
}

int main() {
    p_foo p = &foo;
    int a = 4;
    std::cout << (*p)(&a, 4.2) << std::endl;
}*/
//7 - 1
/*
double harmonic_mean(double a, double b) {
    return (2 / b) * ((b + a) / a);
}

int main() {
    double a, b;
    std::cout << "Enter two numbers:\n";
    while (!(std::cin >> a >> b)) {
        std::cout << "Enter two numbers, please:\n";
        std::cin.clear();
        while(std::cin.get() != '\n') {
            continue;
        }
    }
    std::cout << "Harmonic mean for " << a << " and " << b
              << " is: " << std::setprecision(3) << harmonic_mean(a, b);
}
 */
//7 - 2
/*
int fill_arr(double* arr, int limit) {
    int placed_cnt = 0;
    for (int i = 0; i < limit; ++i) {
        std::cout << "Enter score #" << i + 1 << std::endl;
        while (!(std::cin >> arr[i])) {
            std::cout << "Please, enter float value for score #" << i + 1 << "\n";
            std::cin.clear();
            while(std::cin.get() != '\n') {
                continue;
            }
        }
        ++placed_cnt;
    }
    return placed_cnt;
}

double arr_average(const double* arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}

void show_arr(const double* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
     double* results = new double[10];
     int real_arr_size = fill_arr(results, 10);
     std::cout << "for results ";
     show_arr(results, real_arr_size);
     std::cout << "average is: " << arr_average(results, real_arr_size) << std::endl;
     delete[] results;
}
 */
//7 - 3
/*
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box b) {
    std::cout << "Box made by: " << b.maker << std::endl
              << "height: " << b.height
              << " width: " << b.width
              << " length: " << b.length
              << " volume: " << b.volume << std::endl;
}

void set_volume(box *b) {
    b->volume = b->height * b->width * b->length;
}

int main() {
    box box1 {"Natasha Gusyatnikova", 1, 2, 3};
    show_box(box1);
    set_volume(&box1);
    show_box(box1);
    return 0;
}
 */
//7 - 4
/*
long double probability(unsigned, unsigned);
int main() {
    unsigned total, choices, total_m, choices_m;
    std::cout << "Enter total, picks, total for mega and picks for mega:\n";
    while ((std::cin >> total >> choices >> total_m >> choices_m) &&
           (choices <= total) && (choices_m <= total_m)) {
        std::cout << "You have one chance in ";
        std::cout << probability(total, choices) * probability(total_m, choices_m);
        std::cout << " of winning.\n";
        std::cout << "Next 4 numbers (q to quit):";
    }
    std::cout << "Bye!\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks) {
    long double res = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--) {
        res *= n / p;
    }
    return res;
}
*/
//7 - 5
/*
long long factorial(unsigned);
int main() {
    std::cout << "Let's test factorials:\n";
    unsigned num;
    while (std::cin >> num) {
        std::cout << num << "! is: " << factorial(num) << std::endl;
    }
    std::cout << "Bye!\n";
    return 0;
}

long long factorial(unsigned n) {
    return n == 0 || n == 1 ? 1 : n * factorial(n - 1);
}
 */
//7 - 6
/*
unsigned fill_array(double*, unsigned);
void show_array(const double*, unsigned);
void reverse_array(double*, unsigned);
void swap(double*, double*);
int main() {
    double arr[9];
    unsigned real = fill_array(arr, 9);
    show_array(arr, real);
    reverse_array(arr, real);
    show_array(arr, real);
    return 0;
}
unsigned fill_array(double* arr, unsigned limit) {
    unsigned size = 0;
    for (int i = 0; i < limit; ++i) {
        std::cout << "Enter value #" << i + 1 << std::endl;
        while (!(std::cin >> arr[i])) {
            std::cout << "Please, enter float number:\n";
            std::cin.clear();
            while(std::cin.get() != '\n') continue;
        }
        ++size;
    }
    return size;
}
void show_array(const double* arr, unsigned n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void reverse_array(double* arr, unsigned n) {
    for (int i = 1; i < (n - 1) / 2; ++i) {
        swap(arr + i, arr + n - 1 - i);
    }
}

void swap(double* a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
*/
//7 - 7
/*
double *fill_array(double *, double *);

void show_array(const double *, const double *);

void reverse_array(double *, double *);

void swap(double *, double *);

int main() {
    double arr[9];
    double *end = fill_array(arr, arr + 9);
    show_array(arr, end);
    reverse_array(arr, end);
    show_array(arr, end);
    return 0;
}

double *fill_array(double *begin, double *end) {
    unsigned size = 0;
    double *it;
    for (it = begin; it != end; ++it) {
        std::cout << "Enter value #" << size + 1 << std::endl;
        double tmp;
        while (!(std::cin >> tmp)) {
            std::cout << "Please, enter float number:\n";
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
        }
        if (tmp < 0) break;
        *it = tmp;
        ++size;
    }
    return it;
}

void show_array(const double *begin, const double *end) {
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}

void reverse_array(double *begin, double *end) {
    int n = end - begin;
    for (int i = 1; i < (end - begin - 1) / 2; ++i) {
        swap(begin + i, begin + n - 1 - i);
    }
}

void swap(double *a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 */
//7 - 8
/*
const int seasons = 4;
const std::array<std::string, seasons> snames =
        {"Spring", "Summer", "Fall", "Winter"};
void fill(std::array<double, seasons>* pa);
void show(std::array<double, seasons> da);

int main() {
    std::array<double, seasons> expenses{};
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double, seasons>* pa) {
    for (int i = 0; i < seasons; ++i) {
        std::cout << "Enter " << snames[i] << " expenses:\n";
        std::cin >> (*pa)[i];
    }
}

void show(std::array<double, seasons> da) {
    double total = 0.0;
    std::cout << "EXPENSES\n";
    for (int i = 0; i < seasons; ++i) {
        std::cout << snames[i] << ": $" << da[i] << std::endl;
        total += da[i];
    }
    std::cout << "Total expenses: $" << total << std::endl;
}
 */
//7 - 9
/*
const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(const student *ps);

void display3(const student pa[], int n);

int main() {
    std::cout << "Enter class size:";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get() != '\n') continue;
    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; ++i) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    std::cout << std::endl;
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    std::cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        std::cout << "Enter fullname for student #" << i + 1 << std::endl;
        char fullname[SLEN];
        std::cin.getline(fullname, SLEN);
        if ('\0' == fullname[0]) {
            break;
        }
        std::strcpy(pa[i].fullname, fullname);
        std::cout << "Enter hobby for student #" << i + 1 << std::endl;
        char hobby[SLEN];
        std::cin.getline(hobby, SLEN);
        std::strcpy(pa[i].hobby, hobby);
        std::cout << "Enter oop level for student #" << i + 1 << std::endl;
        std::cin >> pa[i].ooplevel;
        std::cin.get();
    }
    return i;
}

void display1(student st) {
    std::cout << "Student's name is: " << st.fullname
              << "\n hobby is: " << st.hobby
              << "\n oop level is: " << st.ooplevel << std::endl;
}

void display2(const student *ps) {
    std::cout << "Student's name is: " << ps->fullname
              << "\n hobby is: " << ps->hobby
              << "\n oop level is: " << ps->ooplevel << std::endl;
}

void display3(const student pa[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Student's name is: " << pa[i].fullname
                  << "\n hobby is: " << pa[i].hobby
                  << "\n oop level is: " << pa[i].ooplevel << std::endl;
    }
}
 */
//7 - 10
/*
double calculate(double, double, double (*)(double, double));

using f_ptr = double (*)(double, double);

double add(double, double);

double sub(double, double);

double mult(double, double);

int main() {
    std::cout << "Enter two float numbers: (enter second number -99.99 to quit)\n";
    double first, second;
    //double (*func_arr[3]) (double, double) = {add, sub, mult};
    f_ptr func_arr[3]= {add, sub, mult};
    while (std::cin >> first >> second) {
        if (-99.99 == second) break;
        std::cout << "Sum is: " << calculate(first, second, add)
                  << "\nSub is: " << calculate(first, second, sub)
                  << "\nMult is: " << calculate(first, second, mult) << std::endl;

        //for (int i = 0; i < 3; ++i) {
        //    std::cout << "For operation #" << i + 1 << " result is: "
        //             << calculate(first, second, func_arr[i]) << std::endl;
        }
    }

}

double calculate(double x, double y, double (*func)(double, double)) {
    return func(x, y);
}

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}


double mult(double x, double y) {
    return x * y;
}
*/
/*
int main() {
    int arr[] = {1, 2, 3};
    int i1 = 1, i2 = 2, i3 = 3;
    int* arr_ptr[] = {&arr[0], &arr[1], &arr[2]}; // arr of poiners
    std::cout << arr_ptr[0] << " " << arr_ptr[1]
              << " " << arr_ptr[2] << std::endl;
    std::cout << sizeof(arr[0]) << std::endl;
    int (*ptr_to_arr)[3] = &arr;
    std::cout << "Adress of arr[0]: " << arr << std::endl;
    std::cout << "Adress of array: " << *ptr_to_arr;
}
 */



