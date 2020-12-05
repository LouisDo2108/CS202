#include "triangle.h"

//Point
Point::Point()
{
    x = y = 0;
}

Point::Point(const int x)
{
    this->x = this->y = x;
}

Point::Point(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(string exp)
{
    string xcoor, ycoor;
    int i = 0;

    while (!(exp[i] >= 48 && exp[i] <= 57))
        ++i;

    for (i; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
            xcoor += exp[i];
        else
            break;
    }

    while (!(exp[i] >= 48 && exp[i] <= 57))
        ++i;

    for (i; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
            ycoor += exp[i];
        else
            break;
    }

    x = stoi(xcoor);
    y = stoi(ycoor);
}

Point::Point(const Point &rhs)
{
    x = rhs.x;
    y = rhs.y;
}

void Point::output()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

//Triangle

Triangle::Triangle()
{
    Point A(1, 0);
    Point B(0, 0);
    Point C(0, 1);

    this->A = A;
    this->B = B;
    this->C = C;
}

Triangle::Triangle(const Point &A, const Point &B)
{
    Point O(0, 0);
    this->A = A;
    this->B = B;
    this->C = O;
}

Triangle::Triangle(const Point &A, const Point &B, const Point &C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}

Triangle::Triangle(const Triangle &rhs)
{
    A = rhs.A;
    B = rhs.B;
    C = rhs.C;
}

Triangle::Triangle(int a, int b, int c)
{
    Point A(a, 0);
    Point B(0, b);
    Point C(c, 0);

    this->A = A;
    this->B = B;
    this->C = C;
}

void Triangle::output()
{
    cout << "A";
    A.output();
    cout << "B";
    B.output();
    cout << "C";
    C.output();
}