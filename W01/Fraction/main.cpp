#include "fraction.h"

int main()
{
    Fraction a, b, c;

    cout << "Input a" << endl;
    a.input();

    cout << "Input b" << endl;
    b.input();

    cout << "a adds b" << endl;
    c = a.add(b);
    c.output();

    cout << "a substract b" << endl;
    c = a.substract(b);
    c.output();

    cout << "a multiplies by b" << endl;
    c = a.multiply(b);
    c.output();

    cout << "a divides by b" << endl;
    c = a.divide(b);
    c.output();

    cout << "Reduced a: ";
    a.reduce();
    a.output();

    cout << "Reduced b: ";
    b.reduce();
    b.output();

    cout << "Compare a and b" << endl;
    cout << a.compare(b) << endl;

    cout << "Is a positve?" << endl;
    cout << a.isPositive() << endl;

    cout << "Is b negative" << endl;
    cout << b.isNegative() << endl;

    cout << "Is a zero?" << endl;
    cout << a.isZero() << endl;

    return 0;
}