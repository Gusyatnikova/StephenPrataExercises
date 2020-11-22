#include "ch_10_list.h"

List::List() {size = 0;}

bool List::full() {
    return size == MAX;
}

bool List::empty() {
    return size == 0;
}

bool List::push(const Item &it) {
    if (size < MAX) {
        list[size++] = it;
        return true;
    }
    return false;
}

void List::visit(void (*pf) (Item& it)) {
    for (unsigned int i = 0; i < size; ++i) {
        pf(list[i]);
    }
}