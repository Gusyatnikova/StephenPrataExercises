#include<iostream>
#include <ctime>

#include "ch_12_queue.h"

const int MIN_PER_HRS = 60;

bool newcustomer(double x);

int main() {
    std::srand(std::time(0));
    std::cout << "Case study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maxumum size of queue:\n";
    int qs;
    std::cin >> qs;
    Queue line(qs);
    std::cout << "Enter the number of simulation hours:\n";
    int hours;
    std::cin >> hours;

    long cyclelimit = hours * MIN_PER_HRS;
    std::cout << "Enter the average number of customers per hour:\n";
    double perhour;
    std::cin >> perhour;
    double min_per_cust = MIN_PER_HRS / perhour;
    Item temp;

    long turnways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;

    for (long cycle = 0; cycle < cyclelimit; ++cycle) {
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
    } else {
        std::cout << "No customers\n";
    }
    std::cout << "Done!\n";
    return 0;
}

bool newcustomer(double x) {
    return std::rand() * x / RAND_MAX < 1;
}