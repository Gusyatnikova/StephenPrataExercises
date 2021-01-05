#include <ctime>

#include "ch_12_files/ch_12_cow.h"
#include "ch_12_files/ch_12_string2.h"
#include "ch_12_files/ch_12_customer.h"
#include "ch_12_files/ch_12_queue.h"
//12 - 1
/*
int main() {
    Cow c1;
    c1.ShowCow();
    Cow c2("Burenka","muuu", 64);
    c2.ShowCow();
    Cow c3(c2);
    c3.ShowCow();
    c3 = Cow("Mayka", "walking", 20);
    c3.ShowCow();
    c2 = c3;
    c2.ShowCow();
    return 0;
}
*/
//12 - 2
/*
int main() {
    String2 s1 (" and I am a C++ student.");
    String2 s2 = "Please enter your name:\n";
    String2 s3;
    std::cout << s2;
    std::cin >> s3;
    s2 = "My name is " + s3;
    std::cout << s3 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
              << " 'A' characters in it.\n";
    s1 = "red";
    String2 rgb[3] = {
            String2(s1),
            String2("green"),
            String2("blue")
    };
    std::cout << "enter the name of a primary color for mixing light:\n";
    String2 ans;
    bool success = false;
    while(std::cin >> ans) {
        ans.stringlow();
        for (int i = 0; i < 3; ++i) {
            if (ans == rgb[i]) {
                std::cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success) {
            break;
        } else {
            std::cout << "Try again!\n";
        }
    }
    std::cout << "Buye!\n";
    return 0;
}


*/
//12 - 3
/*class Stock {
private:
    //std::string company;
    char* company;
    int shares;
    double share_val;
    double total_val;

    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock &topval(const Stock &s) const;
    friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};

Stock::Stock() {
    company = new char[std::strlen("no name") + 1];
    std::strcpy(company, "no name");
    shares = 0;
    share_val = total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr) {
    //company = co;
    company = new char[co.size() + 1];
    std::strcpy(company, co.c_str());
    if (n < 0) {
        std::cout << "Nuber of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
        share_val = pr;
        set_tot();
    }
}

Stock::~Stock() {
    delete[] company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    } else if (num > shares) {
        std::cout << "You can't sell nore than you have! "
                  << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

const Stock& Stock::topval(const Stock& s) const {
    return s.total_val > total_val ? s : *this;
}

void Stock::show() const {
    std::cout << "Company: " << company
              << "Shares: " << shares << "\n";
    std::cout << "Share price: $" << share_val << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Stock& s) {
    os << "Company: " << s.company
              << "Shares: " << s.shares << "\n";
    os << "Share price: $" << s.share_val << std::endl;
    return os;
}

const int STKS = 4;

int main() {
    Stock stocks[4] {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; ++st) {
        //stocks[st].show();
        std::cout << stocks[st];
    }
    const Stock* top = &stocks[0];
    for (st = 1; st < STKS; ++st) {
        top = &top->topval(stocks[st]);
    }
    std::cout << "\nMost valuable holding:\n";
    top->show();

    return 0;
}*/
//12 - 4
/*
 * struct customer {
    //char fullname[35];
    int payment;
};
using Item = customer;

class Stack{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = 0);
    Stack(const Stack& st);
    ~Stack();
    bool isempy() const { return size == 0; }
    bool isfull() const { return size == 10; }
    bool push(const Item& item);
    bool pop(Item& item);
    Stack& operator=(const Stack& st);
};

Stack::Stack(int n) {
    n >= 10 ? n = 0 : n = n;
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack& st) : Stack(st.size) {
    //pitems = new Item[st.size];
    //size = st.size;
    top = st.top;
    for (int i = 0; i < size; ++i) {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack() {
    delete[] pitems;
}

bool Stack::push(const Item& it) {
    if (top < MAX) {
        pitems[top++] = it;
        ++size;
        return true;
    } else {
        std::cout << "Stack overflow. Operation was terminated.\n";
        return false;
    }
}
bool Stack::pop(Item& item) {
    if (top == 0) {
        std::cout << "Stack is empty. Operation was terminated.\n";
        return false;
    }
    --size;
    item = pitems[--top];
    return true;
}

Stack& Stack::operator=(const Stack& st) {
    if (&st == this) return *this;
    delete[] pitems;
    size = st.size;
    top = st.top;
    for (int i = 0; i < size; ++i) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

int main() {
    int report = 0;
    Stack department;
    bool success;
    Item first = {1000};
    const Item second = {2000};
    success = department.push(first);
    success = department.push(second);
    Item last;
    success = department.pop(last);
    report += last.payment;
    success = department.pop(last);
    report += last.payment;
    std::cout << "report: " << report << std::endl;
    report = 0;
    department.push(first);
    department.push(first);
    department.push(first);
    Stack copy(department);
    Item tmp;
    tmp.payment = 0;
    copy.pop(tmp);
    report += tmp.payment;
    copy.pop(tmp);
    report += tmp.payment;
    department = copy;
    department.pop(tmp);
    report += tmp.payment;
    std::cout << report;
    return 0;
}*/
//12 - 5
/*

const int MIN_PER_HRS = 60;

bool newcustomer(double x);

int main() {
    std::srand(std::time(0));
    std::cout << "Case study: Bank of Heather Automatic Teller\n";
    //std::cout << "Enter maxumum size of queue:\n";
    int qs = 10;
    //std::cin >> qs;
    Queue line(qs);
    //std::cout << "Enter the number of simulation hours:\n";
    int hours = 100;
    //std::cin >> hours;

    long long cyclelimit = hours * MIN_PER_HRS;
    //std::cout << "Enter the average number of customers per hour:\n";
    double perhour = 1;
    //std::cin >> perhour;
    double min_per_cust = MIN_PER_HRS / perhour;
    Item temp;

    long turnways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;
    long long cycle;
    double av_wait_time = 0.0;
    while (av_wait_time < 1.0) {
        min_per_cust = MIN_PER_HRS / perhour++;
        for (cycle = 0; cycle < cyclelimit; ++cycle) {
            if (newcustomer(min_per_cust)) {
                if (line.isFull()) {
                    ++turnways;
                } else {
                    ++customers;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line.isEmpty()) {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                ++served;
            }
            if (wait_time > 0) --wait_time;
            sum_line += line.queueCnt();
        }
        av_wait_time = static_cast<double> (line_wait) / served;
    }

    if (customers > 0) {

 std::cout << "customers accepted: " << customers << std::endl;
        std::cout << "customers served: " << served << std::endl;
        std::cout << "turnaways: " << turnways << std::endl;
        std::cout << "Average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << static_cast<double>(sum_line) / cyclelimit << std::endl;
        std::cout << "Average wait time: "
                  << static_cast<double> (line_wait) / served << " minutes\n";

        std::cout << "Customers per hour to average wait time = 1 min: " << perhour << std::endl;
    } else {
        std::cout << "No customers\n";
    }
    std::cout << "Done!\n";
    return 0;
}

bool newcustomer(double x) {
    return std::rand() * x / RAND_MAX < 1;
}*/
//12 - 6 ???
/*
const int MIN_PER_HRS = 60;

bool newcustomer(double x);

int main() {
    std::srand(std::time(0));
    std::cout << "Case study: Bank of Heather Automatic Teller\n";
    //std::cout << "Enter maxumum size of queue:\n";
    int qs = 10;
    //std::cin >> qs;
    Queue line1(qs);
    Queue line2(qs);
    //std::cout << "Enter the number of simulation hours:\n";
    int hours = 200;
    //std::cin >> hours;

    long long cyclelimit = hours * MIN_PER_HRS;
    //std::cout << "Enter the average number of customers per hour:\n";
    long perhour = 1;
    //std::cin >> perhour;
    double min_per_cust = MIN_PER_HRS / perhour;
    Item temp;

    long turnways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;
    long long cycle;
    double av_wait_time = 0.0;
    while (av_wait_time < 1.0) {
        min_per_cust = MIN_PER_HRS / perhour;
        for (cycle = 0; cycle < cyclelimit; ++cycle) {
            if (newcustomer(min_per_cust)) {
                if (line1.isFull() && line2.isFull()) {
                    ++turnways;
                } else {
                    ++customers;
                    temp.set(cycle);
                    line1.queueCnt() < line2.queueCnt() ? line1.enqueue(temp) : line2.enqueue(temp);
                }
            }
            if (wait_time <= 0 && !line1.isEmpty() && !line2.isEmpty()) {
                line1.dequeue(temp);
                line2.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                ++served;
            }
            if (wait_time > 0) --wait_time;
            sum_line += (line1.queueCnt() + line2.queueCnt()) / 2;
        }
        ++perhour;
        av_wait_time = static_cast<double> (line_wait) / served;
    }

    if (customers > 0) {
        std::cout << "customers accepted: " << customers << std::endl;
        std::cout << "customers served: " << served << std::endl;
        std::cout << "turnaways: " << turnways << std::endl;
        std::cout << "Average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << static_cast<double>(sum_line) / cyclelimit << std::endl;
        std::cout << "Average wait time: "
                  << static_cast<double> (line_wait) / served << " minutes\n";
        std::cout << "Customers per hour to average wait time 1 min: " << perhour << std::endl;
    } else {
        std::cout << "No customers\n";
    }
    std::cout << "Done!\n";
    return 0;
}

bool newcustomer(double x) {
    return std::rand() * x / RAND_MAX < 1;
}*/
