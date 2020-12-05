#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <cmath>

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

class Triangle
{
private:
    Point A, B, C;

public:
    Triangle();
    Triangle(const Point &A, const Point &B);
    Triangle(const Triangle &rhs);
    Triangle(const Point &A, const Point &B, const Point &C);
    Triangle(int a, int b, int c);
    void output();
};

#endif
