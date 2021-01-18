#include "stacktp.h"
#include <string>
#include <iostream>
#include <cctype>
#include <ctime>
//version with automatic size of array
/*
int main() {
    Stack<std::string> st;
    char ch;
    std::string po;
    std::cout << "Please enter A to add a purchase order,\n"
              << "P to process a PO, or Q to quit.\n";
    while (std::cin >> ch && std::toupper(ch) != 'Q') {
        while(std::cin.get() != '\n') continue;
        if (!std::isalpha(ch)) {
            std::cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A' :
            case 'a' :
                std::cout << "Enter a PO number to add:";
                std::cin >> po;
                if (st.isfull())
                    std::cout << "Stack is full\n";
                else
                    st.push(po);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                    std::cout << "Stack is empty\n";
                else {
                    st.pop(po);
                    std::cout << "PO #" << po << " popped.\n";
                    break;
                }
        }
        std::cout << "Please enter A to Add a purchase order,\n"
                  << "P tp process a PO or Q to quit.\n";
    }
    std::cout << "Buye!\n";
    return 0;
}*/
//version with dynamic size of array
/*
const int Num = 10;

int main() {
    std::srand(std::time(0));
    std::cout << "Please enter stack size:";
    int stackSize;
    std::cin >> stackSize;
    Stack<const char*> st(stackSize);
    const char* in[Num] = {
            "1: Hank Gilgamesh", "2: Kiki Ishtar",
            "3: Betty Rocker", "4: Ian Flag",
            "5: Wolfgang Kibble", "6: Portia Koop",
            "7: Joy Almondo", "8: Xavier Paprika",
            "9: Juan Moore", "10: Misha Mache"
    };
    const char* out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num) {
        if (st.isempty()) {
            st.push(in[nextin++]);
        } else if (st.isfull()) {
            st.pop(out[processed++]);
        } else if (std::rand() % 2 && nextin < Num) {
            st.push(in[nextin++]);
        } else {
            st.pop(out[processed++]);
        }
    }
    for (int i = 0; i < Num; ++i) {
        std::cout << out[i] << '\n';
    }
    std::cout << "Bye!\n";
    return 0;
}
*/
