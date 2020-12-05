#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction();
    Fraction(const int n);
    Fraction(const int n, const int d);
    Fraction(const Fraction &rhs);

    Fraction &operator=(const Fraction &rhs);

    bool operator==(const Fraction &rhs);
    bool operator!=(const Fraction &rhs);
    bool operator>=(const Fraction &rhs);
    bool operator>(const Fraction &rhs);
    bool operator<=(const Fraction &rhs);
    bool operator<(const Fraction &rhs);

    Fraction &operator+=(const Fraction &rhs);
    Fraction &operator-=(const Fraction &rhs);
    Fraction &operator*=(const Fraction &rhs);
    Fraction &operator/=(const Fraction &rhs);

    Fraction operator++(int);
    Fraction &operator++();

    Fraction operator--(int);
    Fraction &operator--();

    friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);

    friend ostream &operator<<(ostream &out, const Fraction rhs);

    void reduced();

    explicit operator float() const
    {
        return (float)numerator / (float)denominator;
    }
};

#endif