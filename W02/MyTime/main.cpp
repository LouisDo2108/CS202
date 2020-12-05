#include "mytime.h"

int main()
{
    cout << "MyTime's default constructor: " << endl;
    MyTime a;
    a.output();

    cout << "MyTime's constructor with h, m, s as arguments: " << endl;
    MyTime b(12, 25, 30);
    b.output();

    cout << "MyTime's constructor with h as argument: " << endl;
    MyTime c(8);
    c.output();

    cout << "MyTime's constructor with a MyTime object as argument(Use the previous object): " << endl;
    MyTime d(c);
    d.output();

    cout << "MyTime's constructor with a string as argument: " << endl;
    MyTime e("10:10:10");
    e.output();

    return 0;
}