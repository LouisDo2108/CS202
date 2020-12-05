#include "stack.h"

int main()
{
    ArrayStack a;
    int c, temp;

    cout << "Enter the stack's capacity: ";
    cin >> c;

    a.init(c);

    cout << "Is the stack empty? ";
    cout << a.isEmpty() << endl;

    for (int i = 0; i <= c; ++i)
    {
        cout << "Push some values!" << endl;
        cin >> temp;
        a.push(temp);
    }

    cout << "Is the stack full? ";
    cout << a.isFull() << endl;

    cout << "Peek: " << endl;
    cout << a.peek() << endl;

    cout << "Pop!" << endl;
    int pop = a.pop();
    cout << "Pop value: ";
    cout << pop << endl;

    cout << "Peek: " << endl;
    cout << a.peek() << endl;

    cout << "Clear!" << endl;
    a.clear();

    return 0;
}