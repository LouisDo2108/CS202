#include "triangle.h"

//Point
void Point::input(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::output()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

double Point::distance(Point b)
{
    double d;
    d = sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    return d;
}

double Point::dOx()
{
    return y;
}

double Point::dOy()
{
    return x;
}

//Triangle
void Triangle::input(Point A, Point B, Point C)
{
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

bool Triangle::isValidTriangle()
{
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    if (a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}

void Triangle::triangleType()
{
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    if (a == b && a == c && b == c)
        cout << "Equilateral triangle" << endl;
    else if (a == b || a == c || b == c)
    {
        cout << "Isosceles ";
        double s = area() * 2;

        if (abs(a * a - s) < pow(10, -9) || abs(b * b - s) < pow(10, -9) || abs(c * c - s) < pow(10, -9))
            cout << "right ";
        cout << "triangle" << endl;
    }
    else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        cout << "Right-angled triangle" << endl;
    else
        cout << "Scalene triangle" << endl;
}

double Triangle::perimeter()
{
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    return a + b + c;
}

double Triangle::area()
{
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Point Triangle::center()
{
    Point G;

    G.input((A.dOy() + B.dOy() + C.dOy()) / 3, (A.dOx() + B.dOx() + C.dOx()) / 3);

    return G;
}
