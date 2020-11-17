#include <iostream>
#include <array>
#include <string>
#include <cstring>
//overloading
/*
inline double square(double x) { return x * x;}
double refcube (double& x) {
    x *= x * x;
    return x;
}

int sum(int a, int b) {
    return a + b;
}

int sum(int* a, int b) {
    return *a + b;
}

int sum(const int* a, int b) {
    return *a + b;
}

int sum(unsigned int a, int b) {
    return a + b;
}
double sum(double a, long b) {
    return a + b;
}


int main() {

    //auto sum_res = sum(3U, 44L);

    const double a = 3.0;
    double* pa = const_cast<double *>(&a);
    *pa = 5.3;
    std::cout << "a = " << a << std::endl;
    std::cout << "pa = " << *pa << std::endl;
    //const double* pb = const_cast<double *>(pa);
    //*pb = 5.3;

    const double x = 3.0;
    double& rx = const_cast<double &>(x);
    rx = 5.3;
    std::cout << "x = " << x << std::endl;
    std::cout << "rx = " << rx << std::endl;

    const char* str = "AA";
    const char str1[] = {'a', '\0'};
    auto& d = str;
    d = "e";
    std::cout << "d: " << d << "   &d: " << &d << std::endl;
    std::cout << "str: " << "AA" << "   &str: " << &"AA" << std::endl;
    std::cout << "str1: " << str1 << std::endl;
    return 0;


}
 */
//templates
/*
template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(b) {
    return a + b;
}

template<typename T>
void Swap(T&, T&); // template
template<> void Swap(double&, double&); // explicit specialization of template

void Swap(int a, int b) {
    std::cout << "In const int, const int " << std::endl;
    int tmp = a;
}
void Swap(int& a, int& b) {
    std::cout << "In int&, int& " << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}

double test(int = 1);
double test(int a) {
    return a * 2.2;
}

const int arr_size = 5;
void show(const std::array<int, arr_size>& arr) {
    for (const int cur : arr)
        std::cout << cur << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << test() << std::endl;
    std::array<int, arr_size> my_arr = {0, 1, 2};
    //show(my_arr);
    //short sh_a = 5, sh_b = 117;
    //template void Swap<short> (short&, short&);
    //Swap(sh_a, sh_b);
    //double d_a = 11.11, d_b = 0.0;
    //Swap(d_a, d_b);
    //int int_a = 20'000, int_b = 1000;
    //Swap<int>(int_a, int_b);
    //Swap(int_a, int_b);
    //double res = sum(int_a, 112.009);
    //std::cout << std::showpoint << 1.0 << std::endl;
    //std::cout << 1.0 << std::endl;
    //std::cout << "\"" << 1 << "\"\n";
    //std::cout << R"(")" << 11 << R"(")" << std::endl;
    return 0;
}

template<typename T>
void Swap(T& a, T& b) {
    std::cout << "In template " << std::endl;
    T tmp = a;
    a = b;
    b = tmp;
}

template<> void Swap(double& a, double& b) { //explicit specialization
    std::cout << "In explicit specialization" << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}
*/
//8 - 1
/*
int calls = 0;
void show(const char* str, int cnt = 0) {
    if (cnt == 0) {
        while(*str) {
            std::cout << *str;
            ++str;
        }
    } else {
        for (int i = 0; i < calls; ++i) {
            show(str);
        }
    }
    std::cout << std::endl;
}

int main() {
    const char* arr = "Kiss";
    for (int i = 3; i--;) {
        show(arr);
        ++calls;
    }
    std::cout << "Next call\n";
    show(arr, 5);
    return 0;
}
*/
//8 - 2
/*
struct CandyBar {
    char *name;
    double weight;
    int ccal;
};

void SetCandyBar(CandyBar &cb, const char *c_ptr = "Millenium Munch",
                 double w = 2.85, int ccal = 350) {
    cb.name = const_cast<char *>(c_ptr);
    cb.weight = w;
    cb.ccal = ccal;
}

void ShowCandyBar(const CandyBar& cb) {
    std::cout << cb.name << " : " << cb.weight << " " << cb.ccal << std::endl;
}

int main() {
    CandyBar bar1{};
    SetCandyBar(bar1, "Natasha", 1.11, 543);
    ShowCandyBar(bar1);
    CandyBar bar2{};
    SetCandyBar(bar2);
    ShowCandyBar(bar2);
    return 0;
}
 */
//8 - 3
/*
void ToUpper(std::string& str) {
    for (char& c : str) {
        c = static_cast<char>(std::toupper(c));
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string (q to quit):\n";
    while (std::getline(std::cin, input) && "q" != input) {
        ToUpper(input);
        std::cout << input << std::endl;
        std::cout << "Enter a string (q to quit):\n";
    }
    return 0;
}
 */
//8 - 4
/*
struct stringy {
    char* str;
    int ct;
};

void set(stringy& stringy, char* val) {
    int val_size = 0;
    while(*val) {
        val_size++;
        ++val;
    }
    stringy.str = new char[val_size + 1];
    stringy.ct = val_size;
    val -= val_size;
    strcpy(stringy.str, val);
    stringy.str[val_size] = '\0';
}

template <typename T>
void show(const T& arg, int cnt = 1) {
    for (int i = 0; i < cnt; ++i) {
        std::cout << arg << "\n";
    }
}

template <> void show(const stringy& str, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        std::cout << str.str << "\n";
    }
}
int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    delete[] beany.str;
    return 0;
}
 */
//8 - 5
/*
template <typename T>
T max5(const T* arr) {
    T max = arr[0];
    for (int i = 0; i < 5; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main() {
    int int_arr[] = {-1, 5, 0, 33, 109};
    double double_arr[] = {-1.33, 5.234, 3.012, 33.33, -13.109};
    std::cout << "int: " << max5(int_arr) << "\n"
              << "double: " << max5(double_arr) << "\n";
    return 0;
}
 */
//8 - 6 what is different with initialization of array with string literal?
/*
template <typename T>
T maxn(T arr[], int n) {
    T max = arr[0];
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

typedef char* char_ptr;
template <> char_ptr maxn(char_ptr arr[], int ptr_cnt) {
    char* ptr_to_max = *arr;
    int max_size = 0;
    for (int i = 0; i < ptr_cnt; ++i) {
        int cur_size = 0;
        char* cur_str = arr[i];
        while(*cur_str) {
            cur_size++;
            ++cur_str;
        }
        if (cur_size > max_size) {
            max_size = cur_size;
            ptr_to_max = arr[i];
        }
    }
    return ptr_to_max;
}

int main() {
    int a = 1, b = -1, c = 10, d = -300, e = 600;
    int* test_arr[] = {&a, &b, &c, &d, &e};
    char ar1[] = "Hi";
    char ar2[] = "Hello";
    char ar3[] = "How are you";
    char ar4[] = "ddd";
    char ar5[] = "";
   char* arr[5] {
        ar1,
        ar2,
        ar3,
        ar4,
        ar5
    };
    std::cout << "Initial adresses: \n";
    for (int i = 0; i < 5; ++i) {
        std::cout << static_cast<void*>(arr[i]) << ", ";
    }
    std::cout << std::endl;
    std::cout << static_cast<void*>(maxn(arr, 5)) << std::endl;
    return 0;
}
*/
//8 - 7
/*
template <typename T>
double SumArray(T arr[], int n) {
    std::cout << "template A\n";
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        res += arr[i];
    }
    return res;
}
template <typename T>
double SumArray(T* arr[], int n) {
    std::cout << "template B\n";
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        res += *arr[i];
    }
    return res;
}

struct debts {
    char name[50];
    double amount;
};

int main() {
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] = {
            {"Ima Wolfe", 2400.0},
            {"Ura Foxe", 1300.0},
            {"Iby Stout", 1800.0},
    };
    double* pd[3];
    for (int i = 0; i < 3; ++i) {
        pd[i] = &mr_E[i].amount;
    }
    std::cout << "Cnt of things: " << SumArray(things, 6) << "\n";
    std::cout << "Sum of debts: " << SumArray(pd, 3) << "\n";
    return 0;
}
*/
//large template selection test
/*
template <typename T>
void template_foo(T arr[]) {
    std::cout << "Template A\n";
}

template <typename T>
void template_foo(const T arr[]) {
    std::cout << "Template A const\n";
}

template <typename T>
void template_foo(T* arr[]) {
    std::cout << "Template B\n";
}

template <typename T>
void template_foo(const T* arr[]) {
    std::cout << "Template B const\n";
}

template <> void template_foo(int* arr[]) {
    std::cout << "Specialization for int\n";
}

template <> void template_foo(const int* arr[]) {
    std::cout << "Specialization for int const\n";
}

int main() {
    //template, template with *, specialization, const to int and double

    int a = 1, b = -1, c = 10, d = -300, e = 600;
    int data[] = {a, b, c, d, e};
    int* addresses[] = {&a, &b, &c, &d, &e};
    double da = 1.1, db = -1.1, dc = 1.10, dd = -1.300, de = 1.622;
    double d_data[] = {da, db, dc, dd, de};
    double* d_addresses[] = {&da, &db, &dc, &dd, &de};
    std::cout << "int array:\n";
    template_foo(data); //template A
    template_foo(addresses); //specialization for int
    std::cout << "double array:\n";
    template_foo(d_data);//template A
    template_foo(d_addresses);//template B?

    //with const
    const int ca = 1, cb = -1, cc = 10, cd = -300, ce = 600;
    const int const_data[] = {ca, cb, cc, cd, ce};
    const int* addresses_to_const[] = {&ca, &cb, &cc, &cd, &ce};
    const double cda = 1.1, cdb = -1.1, cdc = 1.10, cdd = -1.300, cde = 1.622;
    const double const_d_data[] = {cda, cdb, cdc, cdd, cde};
    const double* d_addresses_to_const[] = {&cda, &cdb, &cdc, &cdd, &cde};
    std::cout << "__________ const __________\n";
    std::cout << "const int array:\n";
    template_foo(const_data);//template A const
    template_foo(addresses_to_const);//Specialization for int const
    std::cout << "const double array:\n";
    template_foo(const_d_data); //template A const
    template_foo(d_addresses_to_const); //template B const

    char a = 'a', b = 'b', c = 'c', d = 'd', e = 'e';
    char data[] = {a, b, c, d, e, '\0'};
    char* addresses[] = {&a, &b, &c, &d, &e};
    std::cout << "char array:\n";
    template_foo(data); //template A
    template_foo(addresses); //template B
    //with const
    const char const_a = 'a', const_b = 'b', const_c = 'c', const_d = 'd', const_e = 'e';
    const char const_data[] = {const_a, const_b, const_c, const_d, const_e, '\0'};
    const char* addresses_to_const[] = {&const_a, &const_b, &const_c, &const_d, &const_e};
    std::cout << "const char array:\n";
    template_foo(const_data); //template A const
    template_foo(addresses_to_const); //template B const
    //with string literals
    const char* strings[] = {"a", "b", "c", "d", "e"};
    std::cout << "strings array:\n";
    template_foo(strings);//template B const
    return 0;
}
*/
