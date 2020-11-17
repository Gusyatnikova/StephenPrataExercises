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


//6 - 1
/*
int main() {
    char ch;
    while (std::cin.get(ch) && ch != '@') {
        if (!std::isdigit(ch)) {
            std::isupper(ch) ?
                    ch = static_cast<char>(std::tolower(ch)) :
                    ch = static_cast<char>(std::toupper(ch));
            std::cout << ch;
        }
    }
}
 */
//6 - 2
/*
int main() {
    double arr[10] = {0.0};
    double sum = 0;
    int i = 0;
    while (i < 10 && std::cin >> arr[i]) {
        sum += arr[i];
        ++i;
    }
    double middle = 0.0;
    int over_cnt = 0;
    middle = sum / i;
    for (int k = 0; k < i; ++k) {
        if (arr[k] > middle) {
            ++over_cnt;
        }
    }
    std::cout << std::setprecision(4) << "middle: " << middle
              << " numbers over middle: " << over_cnt << std::endl;
}
 */
//6 - 3
/*
int main() {
    std::cout << "Please enter one of the following choices: \n"
              << "c) carnivore"
              << std::setw(20) << "t) tree"
              << std::setw(20) << "p) pianist"
              << std::setw(20) << "g) game\n";
    char input;
    while (std::cin >> input) {
        if ('c' == input || 'p' == input || 't' == input || 'g' == input) {
            break;
        }
        std::cout << "Please, enter a c, p, t or g: \n";
    }
    switch (input) {
        case 'c' :
            std::cout << "A maple is a carnivore";
            break;
        case 'p' :
            std::cout << "A maple is a pianist";
            break;
        case 't' :
            std::cout << "A maple is a tree";
            break;
        case 'g' :
            std::cout << "A maple is a game";
            break;
        default:
            break;
    };
}
 */
//6 - 4
/*
struct bop {
    std::string fullname;
    std::string title;
    std::string bopname;
    int preference;
};

int main() {
    const int arr_size = 3;
    bop arr[arr_size] = {
            {"Natalya Gusyatnikova", "Junior C++", "natusya", 2},
            {"Nata Gus",             "Junior",     "nat",     1},
            {"Na Gu",                "C++",        "gusya",   0},
    };
    std::cout << "Please enter one of the following choices: \n"
              << "a) display by name\n"
              << "b) display by title\n"
              << "c) display by bopname\n"
              << "d) display by name preference\n";
    char input;
    while (std::cin >> input) {
        if (!('a' == input || 'b' == input || 'c' == input
            || 'd' == input || 'q' == input)) {
            std::cout << "Please, enter a, b, c or d: \n";
            continue;
        }
        switch (input) {
            case 'q' :
                std::cout << "Bye!";
                return 0;
            case 'a' :
                for (int i = 0; i < arr_size; ++i) {
                    std::cout << arr[i].fullname << std::endl;
                }
                break;
            case 'b' :
                for (int i = 0; i < arr_size; ++i) {
                    std::cout << arr[i].title << std::endl;
                }
                break;
            case 'c' :
                for (int i = 0; i < arr_size; ++i) {
                    std::cout << arr[i].bopname << std::endl;
                }
                break;
            case 'd' :
                for (int i = 0; i < arr_size; ++i) {
                    switch (arr[i].preference) {
                        case 0:
                            std::cout << arr[i].fullname << std::endl;
                            break;
                        case 1:
                            std::cout << arr[i].title << std::endl;
                            break;
                        case 2:
                            std::cout << arr[i].bopname << std::endl;
                            break;
                    };
                }
                break;
            default:
                break;
        }
    std::cout << "Next choice:\n";
    }
}
*/
//6 - 5
/*
int main() {
    std::cout << "Enter your wage:" << std::endl;
    unsigned int wage;
    while (std::cin >> wage) {
        double result = 0;
        if (wage >= 5000) {
            result += 5'000 * 0;
        }
        if (wage >= 10000) {
            result += 10'000 * 0.1;
        }
        if (wage >= 20000) {
            result += 20'000 * 0.15;
        }
        if (wage >= 35000) {
            result += 3'000 * 0.2;
        }
        std::cout << "Your tax is: " << result << std::endl;
    }
    std::cout << "Buy!";
}
 */
//6 - 6
/*
struct person {
    std::string fullname;
    double sum;
};
int main() {
    std::vector<person> arr;
    std::vector<person> less;
    std::vector<person> over;
    int persons_cnt;
    std::cout << "Enter person's cnt:\n";
    std::cin >> persons_cnt;
    std::cin.get();
    arr.resize(persons_cnt);
    for (int i = 0; i < persons_cnt; ++i) {
        std::cout << "Person #" << i + 1 << std::endl;
        std::cout << "Enter name:";
        std::getline(std::cin, arr[i].fullname);
        std::cout << "Enter sum:";
        std::cin >> arr[i].sum;
        std::cin.get();
        arr[i].sum < 10'000 ? less.push_back(arr[i]) : over.push_back(arr[i]);
    }
    std::cout << "Grand Patrons\n";
    if (over.size() == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < over.size(); ++i) {
            std::cout << over[i].fullname << " -> " << over[i].sum << std::endl;
        }
    }
    std::cout << "Patrons\n";
    if (less.size() == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < less.size(); ++i) {
            std::cout << less[i].fullname << " -> " << less[i].sum << std::endl;
        }
    }
}
 */
//6 - 7
/*
bool isVowel(char c) {
    c = static_cast<char>(std::tolower(c));
    return  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
    std::string quit = "q";
    int vowel = 0;
    int consonant = 0;
    int other = 0;
    std::string cur;
    while (std::cin >> cur) {
        if (cur == quit) {
            break;
        }
        if (std::isalpha(cur[0])) {
            isVowel(cur[0]) ? ++vowel : ++consonant;
        } else {
            ++other;
        }
    }
    std::cout << vowel << " words beginning with vowels\n";
    std::cout << consonant << " words beginning with consononts\n";
    std::cout << other << " others\n";
}
 */
//6 - 8
/*
int main() {
    std::ifstream in;
    in.open("D:\\work_C++\\Books\\Examples\\tmp.txt");
    int symbols_cnt = 0;
    char ch;
    if (in.is_open()) {
        while (in >> ch) {
            ++symbols_cnt;
        }
        in.close();
    }
    std::cout << symbols_cnt;
}
 */
//6 - 9

struct person {
    std::string fullname;
    double sum;
};
int main() {
    std::vector<person> arr;
    std::vector<person> less;
    std::vector<person> over;
    std::fstream file;
    file.open("D:\\work_C++\\Books\\Examples\\tmp.txt");
    if (!file.is_open()) {
        std::cout << "File is not open";
        return -1;
    }
    std::string arr_size_str;
    std::getline(file, arr_size_str);
    int arr_size = std::stoi(arr_size_str);
    arr.resize(arr_size);
    for (int i = 0; i < arr_size; ++i) {
        std::getline(file, arr[i].fullname);
        std::string sum;
        std::getline(file, sum);
        arr[i].sum = std::stoi(sum);
        arr[i].sum > 10'000 ?
        over.push_back(arr[i]) : less.push_back(arr[i]);
    }
    std::cout << "Grand Patrons\n";
    if (over.size() == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < over.size(); ++i) {
            std::cout << over[i].fullname << " -> " << over[i].sum << std::endl;
        }
    }
    std::cout << "Patrons\n";
    if (less.size() == 0) {
        std::cout << "none\n";
    } else {
        for (int i = 0; i < less.size(); ++i) {
            std::cout << less[i].fullname << " -> " << less[i].sum << std::endl;
        }
    }
}
