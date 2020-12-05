#include "triangle.h"

int main()
{
    cout << "----------------Point-----------------" << endl;
    Point A, B, C;
    double x, y;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    A.input(x, y);

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    B.input(x, y);

    cout << "A";
    A.output();

    cout << "B";
    B.output();

    cout << "Distance from point A to B: ";
    cout << A.distance(B) << endl;

    cout << "Distance to Ox of A: ";
    cout << A.dOx() << endl;

    cout << "Distance to Oy of B: ";
    cout << B.dOy() << endl;

    cout << "----------------Triangle-----------------" << endl;
    Triangle ABC;

    cout << "A" << endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    A.input(x, y);

    cout << "B" << endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    B.input(x, y);

    cout << "C" << endl;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    C.input(x, y);

    ABC.input(A, B, C);

    if (ABC.isValidTriangle())
    {
        cout << "Triangle ABC is valid:" << endl;
        ABC.output();
        cout << "Type of triangle: ";
        ABC.triangleType();
        cout << "Perimeter: " << ABC.perimeter() << endl;
        cout << "Area: " << ABC.area() << endl;
        cout << "Center G";
        A = ABC.center();
        A.output();
    }
    else
        cout << "Invalid triangle ABC" << endl;
    return 0;
}