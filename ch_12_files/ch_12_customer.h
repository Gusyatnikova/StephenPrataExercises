#pragma once

#include <cstdlib>

class Customer {
public:
    Customer() { m_arrive = m_pocesstime = 0; }
    void set(long when);
    long when() const { return m_arrive; }
    int ptime() const { return m_pocesstime; }
private:
    long m_arrive;
    long m_pocesstime;
};