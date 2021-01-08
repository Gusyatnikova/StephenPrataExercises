#include "port.h"
#include <cstring>

//__________Port__________//

Port::Port(const char *br, const char *st, int b) {
    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);
    std::strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port &p) {
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p) {
    if (&p == this) return *this;
    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b) {
    if (b > 0) {
        bottles += b;
    } else {
        std::cout << "Invalid arg for +=. Operation aborted.\n";
    }
    return *this;
}

Port &Port::operator-=(int b) {
    if (b > 0) {
        if (bottles - b < 0) {
            std::cout << "You cannot take more than you have. "
                         "Operation aborted.\n";
        }
        bottles -= b;
    } else {
        std::cout << "Invalid arg for +=. Operation aborted.\n";
    }
    return *this;
}

void Port::Show() const {
    std::cout << "Brand: " << brand << '\n';
    std::cout << "Kind: " << style << '\n';
    std::cout << "Bottles: " << bottles << '\n';
}

std::ostream &operator<<(std::ostream &os, const Port &p) {
    std::cout << p.brand << ' ' << p.style << ' ' << p.bottles;
    return os;
}

//__________VintagePort__________//

VintagePort::VintagePort()
        : Port("none", "Vintage"), nickname(nullptr), year(-1) {}

VintagePort::VintagePort(const char *br, int b,
        const char *nn, int y)
        : Port(br, "Vintage", b) {
    nickname = new char [std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &v)
        : Port(v) {
    nickname = new char [std::strlen(v.nickname) + 1];
    std::strcpy(nickname, v.nickname);
    year = v.year;
}

VintagePort& VintagePort::operator=(const VintagePort &v) {
    if (&v == this) return *this;
    Port::operator=(v);
    delete [] nickname;
    nickname = new char [std::strlen(v.nickname) + 1];
    std::strcpy(nickname, v.nickname);
    year = v.year;
    return *this;
}

void VintagePort::Show() const {
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << yeart << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& v) {
    os << (const Port&) v;
    os << v.nickname << ' ' << v.year;
    return os;
}