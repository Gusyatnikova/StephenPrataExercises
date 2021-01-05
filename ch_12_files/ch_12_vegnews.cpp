#include "ch_12_strbad.h"

void callme1(StringBad&);
void callme2(StringBad);
/*
int main() {
    {
        std::cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spanish leaves Bowls for Dollars");
        std::cout << "headline1: " << headline1 << "\n";
        std::cout << "headline2: " << headline2 << "\n";
        std::cout << "sports: " << sports << "\n";
        callme1(headline1);
        std::cout << "headline1: " << headline1 << "\n";
        callme2(headline2);
        std::cout << "headline2: " << headline2 << "\n";
        std::cout << "Initializing one object to another:\n";
        //Now have to ptrs to one string => need copy cstr
        StringBad sailor = sports;
        //StringBad sailor = StringBad(sports);
        //StringBad sailor(sports);
        std::cout << "sailor: " << sailor << "\n";
        std::cout << "Assign one object to another\n";
        StringBad knot;
        //Need not automatic-generated assignment operation
        knot = headline1;
        std::cout << "knot: " << knot << "\n";
        std::cout << "Exiting the block.\n";
    }
    std::cout << "End of main()\n";

    return 0;
}*/

void callme1(StringBad& rsb) {
    std::cout << "String2 passed by reference:\n";
    std::cout << "___\"" << rsb << "\"\n";
}
//copy cstr
void callme2(StringBad sb) {
    std::cout << "String2 passed by value:\n";
    std::cout << "___\"" << sb << "\"\n";
}