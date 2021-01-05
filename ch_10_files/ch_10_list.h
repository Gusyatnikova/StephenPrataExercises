#pragma once

using Item = double;

class List{
private:
    const static int MAX = 5;
    Item list[MAX];
    unsigned int size;
public:
    List();
    bool push(const Item& it);
    bool empty();
    bool full();
    void visit(void (*pf) (Item&));
};