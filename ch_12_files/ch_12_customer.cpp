#include "ch_12_customer.h"

void Customer::set(long when) {
    m_arrive = when;
    m_pocesstime = std::rand() % 3 + 1;
}