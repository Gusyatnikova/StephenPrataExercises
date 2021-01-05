#include "ch_12_queue.h"

Queue::Queue(int qs) : m_qsize(qs) {
    m_front = m_rear = nullptr;
    m_items = 0;
}

Queue::~Queue() {
    Node * tmp;
    while (m_front) {
        tmp = m_front;
        m_front = m_front->next;
        delete tmp;
    }
}

bool Queue::isEmpty() const { return m_items == 0; }

bool Queue::isFull() const { return m_items == m_qsize; }

int Queue::queueCnt() const { return m_items; }

bool Queue::enqueue(const Item &item) {
    if (isFull()) return false;
    Node* new_node = new Node;
    new_node->data = item;
    new_node->next = nullptr;
    ++m_items;
    if (m_front == nullptr) {
        m_front = new_node;
    } else {
        m_rear->next = new_node;
    }
    m_rear = new_node;
    return true;
}

bool Queue::dequeue(Item &item) {
    if (isEmpty()) return false;
    item = m_front->data;
    --m_items;
    Node* tmp = m_front;
    m_front = m_front->next;
    delete tmp;
    if (m_items == 0) m_rear = nullptr;
    return true;
}