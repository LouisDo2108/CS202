#include "point.h"

int main()
{
    cout << "Default constructor" << endl;
    Point a;
    a.output();

    cout << "Constructor with 1 integer argument" << endl;
    Point b(7);
    b.output();

    cout << "Constructor with 2 integer arguments" << endl;
    Point c(7, 4);
    c.output();

    cout << "Constructor with a string as argument" << endl;
    Point d("(1, 2)");
    d.output();

    cout << "Constructor with a fraction object as argument (Use the previous point)" << endl;
    Point e(d);
    e.output();
    return 0;
}
