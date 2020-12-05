#include "fraction.h"

int main()
{

    cout << "Default constructor" << endl;
    Fraction a;
    a.output();

    cout << "Constructor with 1 integer argument" << endl;
    Fraction b(7);
    b.output();

    cout << "Constructor with 2 integer arguments" << endl;
    Fraction c(1, 3);
    c.output();

    cout << "Constructor with a string as argument" << endl;
    Fraction d("13/11");
    d.output();

    cout << "Constructor with a fraction object as argument (Use the previous fraction)" << endl;
    Fraction e(d);
    e.output();
}