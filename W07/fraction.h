#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <string>
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

    bool operator==(const Fraction &rhs) const;
    bool operator!=(const Fraction &rhs) const;
    bool operator>=(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    bool operator<=(const Fraction &rhs) const;
    bool operator<(const Fraction &rhs) const;

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
    friend bool comparator(const Fraction &lhs, const Fraction &rhs);

    friend ostream &operator<<(ostream &out, const Fraction rhs);

    void reduced();

    explicit operator float() const
    {
        return (float)numerator / (float)denominator;
    }

    explicit operator string() const
    {
        return to_string(numerator) + "/" + to_string(denominator);
    }
};

#endif