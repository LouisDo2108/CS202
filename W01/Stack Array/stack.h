#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

class ArrayStack
{
private:
    int *data, capacity, top;

public:
    void init(int capacity);
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};

#endif