#include "stack.h"

void ArrayStack::init(int capacity)
{
    this->capacity = capacity;
    data = new int[capacity]{};
    top = 0;
}

void ArrayStack::push(int x)
{
    if (!isFull())
        data[top++] = x;
    else
        cout << "Stack is full! Can not push" << endl;
}

int ArrayStack::pop()
{
    --top;
    return data[top];
}

int ArrayStack::peek()
{
    if (!isEmpty())
        return data[top - 1];
    cout << "Stack is empty! Can not peek" << endl;
    return INT_MIN;
}

bool ArrayStack::isEmpty()
{
    if (top <= 0)
        return true;
    return false;
}

bool ArrayStack::isFull()
{
    if (top >= capacity)
        return true;
    return false;
}

void ArrayStack::clear()
{
    delete data;
}