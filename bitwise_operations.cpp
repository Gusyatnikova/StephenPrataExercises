#include <iostream>
/*code for bitewise operation training
 * https://informatics.mccme.ru/mod/statements/view.php?id=43650#1*/
//1
/*
int main (int argc, char* argv[]) {
    int power;
    std::cin >> power;
    std::cout << (1 << power);
    return 0;
}
*/
//2
/*
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    if (i > 7) return 0;
    std::cout << int((a & ~(1U << i)));
    return 0;
}
*/
//3
/*
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    unsigned char mask = 1;
    std::cout << bool((1U << i) & a);
    return 0;
}
 */
//4 invert bit
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    unsigned char mask = 1;
    std::cout << int(a ^ (mask << i));
    return 0;
}
