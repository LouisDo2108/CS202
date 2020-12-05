#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <algorithm>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    void input();
    void output();
    Fraction add(Fraction b);
    Fraction substract(Fraction b);
    Fraction multiply(Fraction b);
    Fraction divide(Fraction b);
    void reduce();
    int compare(Fraction b);
    bool isPositive();
    bool isNegative();
    bool isZero();
};

#endif