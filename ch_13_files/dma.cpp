#include "dma.h"
#include <cstring>
//initial
/*
//__________baseDMA__________//

baseDMA::baseDMA(const char *l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA() { delete [] label; }

baseDMA& baseDMA::operator=(const baseDMA &rhs) {
    if (this == &rhs) return *this;
    delete [] label;
    label = new char[std::strlen(rhs.label) + 1];
    std::strcpy(label, rhs.label);
    rating = rhs.rating;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const baseDMA &r) {
    os << "Label: " << r.label << '\n';
    os << "Rating: " << r.rating << '\n';
    return os;
}

//__________lacksDMA__________//

lacksDMA::lacksDMA(const char *c, const char *l, int r)
        : baseDMA(l, r) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs)
        : baseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream &os, const lacksDMA &l) {
    os << dynamic_cast<baseDMA&>(const_cast<lacksDMA&>(l));
    //os << (const baseDMA&)l;
    os << "Color: " << l.color << '\n';
    return os;
}

//__________hasDMA__________//

hasDMA::hasDMA(const char *s, const char *l, int r)
        : baseDMA(l, r) {
    style = new char [std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &r)
        : baseDMA(r) {
    style = new char [std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &h)
        : baseDMA(h) {
    style = new char [std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA& hasDMA::operator=(const hasDMA &h) {
    if (&h == this) return *this;
    baseDMA::operator=(h);
    delete [] style;
    style = new char [std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
    return *this;
}

std::ostream& operator<<(std::ostream &os, const hasDMA &h) {
    os << (const baseDMA&) h;
    os << "Style: " << h.style << '\n';
    return os;
}*/
//with abstract base class (for 13 - 3)
//__________AbstractDMA__________//

AbstractDMA::AbstractDMA(const std::string& l) {
    label = new char [l.size() + 1];
    std::strcpy(label, l.c_str());
}

AbstractDMA::AbstractDMA(const AbstractDMA &aDma) {
    label = new char [std::strlen(aDma.label) + 1];
    std::strcpy(label, aDma.label);
}

AbstractDMA::AbstractDMA() { label = nullptr; }

AbstractDMA::~AbstractDMA() { delete [] label; }

AbstractDMA& AbstractDMA::operator=(const AbstractDMA &aDma) {
    if (&aDma == this) return *this;
    delete [] label;
    label = new char [std::strlen(aDma.label) + 1];
    std::strcpy(label, aDma.label);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AbstractDMA &aDma) {
    std::cout << "Label: " << aDma.label << '\n';
    return os;
}

//__________baseDMA__________//

baseDMA::baseDMA(const std::string &l, int r)
        : AbstractDMA(l), rating(r) {}

baseDMA::baseDMA(const baseDMA &rs)
        : AbstractDMA(rs), rating(rs.rating) {}

baseDMA::~baseDMA() {}

baseDMA& baseDMA::operator=(const baseDMA &rhs) {
    if (this == &rhs) return *this;
    AbstractDMA::operator=(rhs);
    rating = rhs.rating;
    return *this;
}

void baseDMA::View() const {
    std::cout << "baseDMA. Rating: " << rating << '\n';
}

std::ostream& operator<<(std::ostream &os, const baseDMA &r) {
    os << (const AbstractDMA&) r;
    os << "Rating: " << r.rating << '\n';
    return os;
}

//__________lacksDMA__________//

lacksDMA::lacksDMA(const std::string &c, const std::string &l)
        : AbstractDMA(l) {
    std::strncpy(color, c.c_str(), COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const std::string &c, const AbstractDMA &rs)
        : AbstractDMA(rs) {
    std::strncpy(color, c.c_str(), COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const {
    std::cout << "lacksDMA. Color: " << color << '\n';
}

std::ostream& operator<<(std::ostream &os, const lacksDMA &l) {
    os << dynamic_cast<AbstractDMA&>(const_cast<lacksDMA&>(l));
    //os << (const baseDMA&)l;
    os << "Color: " << l.color << '\n';
    return os;
}

//__________hasDMA__________//

hasDMA::hasDMA(const std::string &s, const std::string &l)
        : AbstractDMA(l) {
    style = new char [s.size() + 1];
    std::strcpy(style, s.c_str());
}

hasDMA::hasDMA(const std::string &s, const AbstractDMA &r)
        : AbstractDMA(r) {
    style = new char [s.size() + 1];
    std::strcpy(style, s.c_str());
}

hasDMA::hasDMA(const hasDMA &h)
        : AbstractDMA(h) {
    style = new char [std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA& hasDMA::operator=(const hasDMA &h) {
    if (&h == this) return *this;
    AbstractDMA::operator=(h);
    delete [] style;
    style = new char [std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
    return *this;
}

void hasDMA::View() const {
    std::cout << "hasDMA. Style: " << style << '\n';
}

std::ostream& operator<<(std::ostream &os, const hasDMA &h) {
    os << (const AbstractDMA&) h;
    os << "Style: " << h.style << '\n';
    return os;
}