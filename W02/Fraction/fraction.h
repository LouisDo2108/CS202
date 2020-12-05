#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction();
    Fraction(const int n, const int d);
    Fraction(const int n);
    Fraction(const string exp);
    Fraction(const Fraction &rhs);

    void output();
};

#endif