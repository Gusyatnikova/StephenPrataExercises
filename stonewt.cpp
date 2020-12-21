#include "stonewt.h"


Stonewt::Stonewt(double value, Mode form) {
    if (form == STONE) {
        stone = static_cast<int>(value);
        pounds = stone * Lbs_per_stn;
        pds_left = 0;
        mode = form;
    } else if (form == POUNDS) {
        stone = static_cast<int>(value) / Lbs_per_stn;
        pounds = static_cast<int>(value);
        pds_left = 0.0;
        mode = form;
    } else if (form == FLOAT_POUNDS) {
        stone = static_cast<int>(value) / Lbs_per_stn;
        pounds = static_cast<int>(value);
        pds_left = value - static_cast<int>(value);
        mode = form;
    }
}

/*Stonewt::Stonewt(int stn, double lbs, Mode form) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}*/

Stonewt::Stonewt() {
    mode = Stonewt::STONE;
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {}

Stonewt Stonewt::operator+(const Stonewt &st) const {
    if (mode == Stonewt::STONE) return Stonewt(stone + st.stone, Stonewt::STONE);
    else if (mode == Stonewt::POUNDS) return Stonewt(pounds + st.pounds, Stonewt::POUNDS);
    else return Stonewt(
                pounds + pds_left + st.pounds + st.pds_left, Stonewt::FLOAT_POUNDS);
}

Stonewt Stonewt::operator-(const Stonewt &st) const {
    if (mode == Stonewt::STONE) return Stonewt(stone - st.stone, Stonewt::STONE);
    if (mode == Stonewt::POUNDS) return Stonewt(pounds - st.pounds, Stonewt::POUNDS);
    else return Stonewt(
                pounds + pds_left - st.pounds - st.pds_left, Stonewt::FLOAT_POUNDS);
}

Stonewt Stonewt::operator*(const Stonewt &st) const {
    if (mode == Stonewt::STONE) return Stonewt(stone * st.stone, STONE);
    if (mode == Stonewt::POUNDS) return Stonewt(pounds * st.pounds, POUNDS);
    else return Stonewt(
            (pounds + pds_left) * (st.pounds + st.pds_left), FLOAT_POUNDS);
}

Stonewt operator*(double num, const Stonewt &st) {
    if (st.mode == Stonewt::STONE)
        return Stonewt(st.stone * num, Stonewt::STONE);
    if (st.mode == Stonewt::POUNDS)
        return Stonewt(num * st.pounds, Stonewt::POUNDS);
    else
        return Stonewt(
                (st.pounds + st.pds_left) * num, Stonewt::FLOAT_POUNDS);
}

Stonewt operator*(const Stonewt &st, double num) {
    return num * st;
}

bool Stonewt::operator<(const Stonewt &rhs) const {
    return pounds < rhs.pounds;
}

bool Stonewt::operator>(const Stonewt &rhs) const {
    return !(*this <= rhs);
}

bool Stonewt::operator==(const Stonewt &rhs) const {
    return pounds == rhs.pounds;
}

bool Stonewt::operator!=(const Stonewt &rhs) const {
    return !(*this == rhs);
}

bool Stonewt::operator<=(const Stonewt &rhs) const {
    return (*this == rhs) || (*this < rhs);
}

bool Stonewt::operator>=(const Stonewt &rhs) const {
    return !(*this < rhs);
}

/*void Stonewt::show_lbs() const {
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_stn() const {
    std::cout << pounds << " pounds\n";
}*/

std::ostream &operator<<(std::ostream &os, const Stonewt &st) {
    switch (st.mode) {
        case Stonewt::STONE:
            os << st.stone << " stone\n";
            break;
        case Stonewt::POUNDS:
            os << st.pounds << " pounds\n";
            break;
        case Stonewt::FLOAT_POUNDS:
            os << st.pounds + st.pds_left << " float pounds\n";
            break;
        default:
            os << "Stonewt object is invalid\n";
            break;
    }
    return os;
}
