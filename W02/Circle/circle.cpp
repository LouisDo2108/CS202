#include "circle.h"

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
    cout << "(" << x << ", " << y << ")";
}

Circle::Circle()
{
    Point O;
    this->O = O;
    r = 1;
}

Circle::Circle(const Point &O, int r)
{
    this->O = O;
    this->r = r;
}

Circle::Circle(int k)
{
    Point O;
    this->O = O;
    this->r = k;
}

Circle::Circle(string exp)
{
    Point O(exp);
    this->O = O;

    string radius;

    int i = exp.length() - 1;
    while ((exp[i] >= 48 && exp[i <= 57]))
    {
        radius += exp[i];
        --i;
    }
    reverse(radius.begin(), radius.end());
    r = stoi(radius);
}

Circle::Circle(const Point &O)
{
    this->O = O;
    r = 1;
}

void Circle::output()
{
    cout << "O";
    O.output();
    cout << ", r = " << r << endl;
}
