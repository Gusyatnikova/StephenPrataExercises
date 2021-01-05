#pragma once

#include <string>

#include "ch_12_customer.h"

using Item = Customer;

class Queue {
public:
    Queue(int qs = Q_SIZE);
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;
    int queueCnt() const;
    bool enqueue(const Item& item);
    bool dequeue(Item& item);

    Queue(const Queue& q) = delete;
    Queue& operator=(const Queue& q) = delete;
private:
    struct Node {
        Item data;
        Node* next;
    };
    enum {Q_SIZE = 10};

    const int m_qsize;
    Node* m_front;
    Node* m_rear;
    int m_items;
};