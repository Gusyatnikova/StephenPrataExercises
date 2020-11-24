#include <iostream>
#include <bitset>
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
/*
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    unsigned char mask = 1;
    std::cout << int(a ^ (mask << i));
    return 0;
}
 */
//5 Zero all bits except the last n
/*
int main() {
    int a;
    unsigned int n;
    std::cin >> a >> n;
    unsigned int mask = 0;
    for (int i = 0; i < n; ++i) {
        mask |= (1U << i);
    }
    std::cout << int(a & mask);
    return 0;
}
//6 cout byte value bit by bit
 */
/*
int main() {
    unsigned int a;
    std::cin >> a;
    std::bitset<8> bs(a);
    std::cout << bs;
    return 0;
}
 */
//7 Zero given last bist
/*
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    a >>= i;
    std::cout << (a << i);
    return 0;
}
 */
//8 2^n + 2^m
/*
int main() {
    int n, m;
    std::cin >> n >> m;
    int res = (1U << n) | (1U << m);
    std::cout << res;
    return 0;
}
 */
//9 set bit in 1
/*
int main() {
    int a;
    unsigned int i;
    std::cin >> a >> i;
    std::cout << int (a | (1U << i));
    return 0;
}
 */