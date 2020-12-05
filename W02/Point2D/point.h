#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
    Point();
    Point(const int x);
    Point(const int x, const int y);
    Point(string exp);
    Point(const Point &rhs);
    void output();

private:
    int x, y;
};

#endif