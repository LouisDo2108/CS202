#include "fraction.h"

Fraction::Fraction() : numerator(0), denominator(1){};

Fraction::Fraction(const int n) : numerator(n), denominator(1){};

Fraction::Fraction(const int n, const int d)
{
    if (d == 0)
    {
        cout << "Denominator can't be 0" << endl;
        exit(0);
    }
    if (d < 0)
    {
        numerator = n * (-1);
        denominator = d * (-1);
    }
    else
    {
        numerator = n;
        denominator = d;
    }
    this->reduced();
}

Fraction::Fraction(const Fraction &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    this->reduced();
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction &rhs) const
{
    return numerator * rhs.denominator == denominator * rhs.numerator;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
    return numerator * rhs.denominator != denominator * rhs.numerator;
}

bool Fraction::operator>=(const Fraction &rhs) const
{
    return numerator * rhs.denominator >= denominator * rhs.numerator;
}

bool Fraction::operator>(const Fraction &rhs) const
{
    return numerator * rhs.denominator > denominator * rhs.numerator;
}

bool Fraction::operator<=(const Fraction &rhs) const
{
    return numerator * rhs.denominator <= denominator * rhs.numerator;
}

bool Fraction::operator<(const Fraction &rhs) const
{
    return numerator * rhs.denominator < denominator * rhs.numerator;
}

Fraction &Fraction::operator+=(const Fraction &rhs)
{
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator *= rhs.denominator;
    if (numerator < 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &rhs)
{
    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator *= rhs.denominator;
    if (numerator < 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &rhs)
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    if (numerator < 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &rhs)
{
    if (rhs.denominator == 0)
        exit(1);
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    if (numerator < 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    numerator += denominator;
    return temp;
}

Fraction &Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    numerator -= denominator;
    return temp;
}

Fraction &Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

ostream &operator<<(ostream &out, const Fraction rhs)
{
    out << rhs.numerator << "/" << rhs.denominator << " = " << (float)rhs.numerator / (float)rhs.denominator << endl;
    return out;
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs)
{
    Fraction temp(lhs);
    temp += rhs;
    return temp;
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs)
{
    Fraction temp(lhs);
    temp -= rhs;
    return temp;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    Fraction temp(lhs);
    temp *= rhs;
    return temp;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs)
{
    Fraction temp(lhs);
    temp /= rhs;
    return temp;
}

void Fraction::reduced()
{
    int gcd = __gcd(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;
}
