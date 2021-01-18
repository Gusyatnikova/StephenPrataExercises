#include "emp.h"

//__________abstr_emp__________//
abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string &fn,
                     const std::string &ln, const std::string &j)
        : fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::SetAll() {
    std::cout << "Enter first name:\n";
    std::cin >> fname;
    std::cout << "Enter last name:\n";
    std::cin >> lname;
    std::cout << "Enter job:\n";
    std::cin >> job;
}

void abstr_emp::ShowAll() const {
    std::cout << "abstr_emp:\n";
    std::cout << fname << ' ' << lname << ' ' << job << '\n';
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e) {
    std::cout << e.fname << ' ' << e.lname;
    return os;
}

//__________employee__________//

employee::employee() {}

employee::employee(const std::string &fn,
                   const std::string &ln, const std::string &job)
        : abstr_emp(fn, ln, job) {}

void employee::ShowAll() const {
    std::cout << "employee:\n";
    abstr_emp::ShowAll();
}

void employee::SetAll() { abstr_emp::SetAll(); }

//__________manager__________//

manager::manager() {}

manager::manager(const std::string &fn, const std::string &ln,
                 const std::string &j, int ico)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico)
        : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager &m)
        : abstr_emp(m), inchargeof(m.inchargeof) {}

manager::~manager() {}

void manager::ShowAll() const {
    std::cout << "manager:\n";
    abstr_emp::ShowAll();
    std::cout << inchargeof << '\n';
    ;
}

void manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter in charge of:";
    std::cin >> inchargeof;
}

//__________fink__________//

fink::fink() {}

fink::fink(const std::string &fn, const std::string &ln,
           const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo)
        : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &m)
        : abstr_emp(m), reportsto(m.reportsto) {}

void fink::ShowAll() const {
    std::cout << "fink:\n";
    abstr_emp::ShowAll();
    std::cout << ' ' << reportsto << '\n';
}

void fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Enter reports to: ";
    std::getline(std::cin, reportsto);
}

//__________highfink__________//

highfink::highfink()
    : abstr_emp(), manager(), fink() {}

highfink::~highfink() {}

highfink::highfink(const std::string& fn, const std::string& ln,
         const std::string& j, const std::string& rpo, int ico)
         : abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
         fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp& e, const std::string & rpo, int ico)
        : abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink &m, int ico)
        : abstr_emp(m), manager((const abstr_emp&)m, ico), fink(m) {}

highfink::highfink(const manager &m, const std::string& rpo)
        : abstr_emp(m), manager(m), fink((const abstr_emp&)m, rpo) {}

highfink::highfink(const highfink& h)
        : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
    std::cout << "highfink:\n";
    manager::ShowAll();
    std::cout << '\n';
    fink::ReportsTo();
    std::cout << '\n';
}

void highfink::SetAll() {
    manager::SetAll();
    std::cout << "Enter roports to:";
    std::cin >> fink::ReportcTo();
}