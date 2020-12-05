#include "queue.h"

void LinkedListQueue::init(int capacity)
{
    head = tail = nullptr;
    this->capacity = capacity;
    num = 0;
}

void LinkedListQueue::enqueue(int x)
{
    if (!isFull())
    {
        Node *temp = new Node;
        temp->p_next = nullptr;
        temp->v = x;

        if (!head && !tail)
            head = tail = temp;
        else
        {
            tail->p_next = temp;
            tail = tail->p_next;
        }
        ++num;
    }
}

int LinkedListQueue::dequeue()
{
    int output = head->v;
    Node *temp = head;
    head = head->p_next;
    delete temp;
    --num;
    return output;
}

int LinkedListQueue::peek()
{
    return head->v;
}

bool LinkedListQueue::isEmpty()
{
    if (num <= 0)
        return true;
    return false;
}

bool LinkedListQueue::isFull()
{
    if (num >= capacity)
        return true;
    return false;
}

void LinkedListQueue::clear()
{
    Node *cur = head, *del;
    while (cur)
    {
        del = cur;
        cur = cur->p_next;
        delete del;
    }
}