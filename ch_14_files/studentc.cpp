#include "studentc.h"

//__________Student__________//

double Student::Average() const {
    return scores.size() > 0 ?
        scores.sum() / scores.size() : 0;
}

std::ostream& Student::arr_out(std::ostream &os) const {
    int i;
    int lim = scores.size();
    if (lim <= 0) {
        os << "Empty array ";
    } else {
        for (i = 0; i < lim; ++i) {
            os << scores[i] << " ";
            if (i % 5 == 4) os << std::endl;
        }
        if (i % 5 != 0) os << std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, const Student &student) {
    os << "Scores for " << student.name << ":\n";
    student.arr_out(os);
    return os;
}

std::istream& operator>>(std::istream &is, Student &student) {
    is >> student.name;
    return is;
}

std::istream& getline(std::istream &is, Student &student) {
    getline(is, student.name);
    return is;
}

//__________Student1__________//

double Student1::Average() const {
    return ArrayDb::size() > 0 ?
           ArrayDb::sum() / ArrayDb::size() : 0;
}

const std::string& Student1::Name() const {
    return (const std::string&)*this;
}

std::ostream& operator<<(std::ostream& os, const Student1 &student) {
    os << "Scores for " << (const std::string&)student << ":\n";
    student.arr_out(os);
    return os;
}

double Student1::operator[](int i) const {
    return ArrayDb::operator[](i);
}

double& Student1::operator[](int i) {
    return ArrayDb::operator[](i);
}

std::istream& operator>>(std::istream &is, Student1 &student) {
    is >> (std::string&) student;
    return is;
}

std::istream& getline(std::istream &is, Student1 &student) {
    getline(is,(std::string&) student);
    return is;
}

std::ostream& Student1::arr_out(std::ostream &os) const {
    int i;
    int lim = ArrayDb::size();
    if (lim <= 0) {
        os << "Empty array ";
    } else {
        for (i = 0; i < lim; ++i) {
            os << ArrayDb ::operator[](i) << " ";
            if (i % 5 == 4) os << std::endl;
        }
        if (i % 5 != 0) os << std::endl;
    }
    return os;
}