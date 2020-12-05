#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <algorithm>

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

class Circle
{
public:
    Circle();
    Circle(const Point &O, int r);
    Circle(int k);
    Circle(string exp);
    Circle(const Point &O);
    void output();

private:
    Point O;
    int r;
};

#endif