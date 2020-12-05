#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct Node
{
    int v;
    Node *p_next;
};

class LinkedListQueue
{
private:
    Node *head;
    Node *tail;
    int capacity, num;

public:
    void init(int capacity);
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};

#endif