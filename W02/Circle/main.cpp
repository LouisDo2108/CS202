#include "circle.h"

int main()
{
    cout << "Circle's default constructor: " << endl;
    Circle A;
    A.output();

    cout << "Circle with a radius as argument: " << endl;
    Circle B(3);
    B.output();

    Point a(1, 2);
    cout << "Circle with a origin and radius as arguments: " << endl;
    Circle C(a, 5);
    C.output();

    cout << "Circle with a string as argument: " << endl;
    Circle D("O(5, 3), r = 5");
    D.output();

    cout << "Circle with an origin as argument: " << endl;
    Circle E(a);
    E.output();

    return 0;
}