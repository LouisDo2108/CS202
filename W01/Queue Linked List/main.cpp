#include "queue.h"

int main()
{
    LinkedListQueue l;
    l.init(5);

    l.enqueue(3);

    int p = l.peek();
    int d = l.dequeue();

    cout << "Peek: " << p << endl;
    cout << "Dequeue: " << d << endl;

    cout << "Is the queue empty? ";
    cout << l.isEmpty() << endl;

    cout << "Is the queue full? ";
    cout << l.isFull() << endl;

    cout << "Clear!" << endl;
    l.clear();
    return 0;
}