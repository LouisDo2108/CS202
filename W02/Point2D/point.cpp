#include "point.h"

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