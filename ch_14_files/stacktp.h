#pragma once
//version with automatic size of array
/*
template<typename T>
class Stack {
private:
    enum {MAX = 10};
    T items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const T &item);
    bool pop(T &item);
};

template<typename T>
Stack<T>::Stack() : top(0) {}

template<typename T>
bool Stack<T>::isfull() const { return top == MAX; }

template<typename T>
bool Stack<T>::isempty() const { return top == 0; }

template<typename T>
bool Stack<T>::push(const T &item) {
    if (isfull()) return false;
    items[top++] = item;
    return true;
}

template<typename T>
bool Stack<T>::pop(T &item) {
    if (isempty()) return false;
    item = items[--top];
    return true;
}*/
////version with dynamic size of array

template<typename T>
class Stack {
private:
    enum {SIZE = 10};
    int size;
    T *items;
    int top;
public:
    explicit Stack(int s = SIZE);
    Stack(const Stack& st);
    ~Stack() {delete [] items; }
    bool isempty() const {return top == 0; }
    bool isfull() const { return top == size; }
    bool push(const T &item);
    bool pop(T &item);
    Stack& operator=(const Stack &stack);
};

template <typename T>
Stack<T>::Stack(int s) {
    size = s;
    items = new T[size];
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack & stack) {
    size = stack.size;
    items = new T[size];
    for (int i = 0; i < size; ++i) {
        items[i] = stack.items[i];
    }
    top = stack.top;
}

template <typename  T>
bool Stack<T>::push(const T &item) {
    if (isfull()) return false;
    items[top++] = item;
    return true;
}

template <typename T>
bool Stack<T>::pop(T &item) {
    if (isempty()) return false;
    item = items[--top];
    return true;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack &stack) {
    if (&stack == this) return *this;
    delete [] items;
    size = stack.size;
    items = new T[size];
    for (int i = 0; i < size; ++i) {
        items[i] = stack[i];
    }
    top = stack.top;
    return *this;
}