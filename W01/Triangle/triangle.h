#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x, y;

public:
    void input(double x, double y);
    void output();
    double distance(Point b);
    double dOx();
    double dOy();
};

class Triangle
{
private:
    Point A, B, C;

public:
    void input(Point A, Point B, Point C);
    void output();
    bool isValidTriangle();
    void triangleType();
    double perimeter();
    double area();
    Point center();
};

#endif
