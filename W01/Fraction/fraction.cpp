#include "fraction.h"

void Fraction::input()
{
    cout << "Input the numerator: ";
    cin >> numerator;
    cout << "Input the denominator: ";
    cin >> denominator;
}

void Fraction::output()
{
    cout << numerator << "/" << denominator << " = " << (float)numerator / (float)(denominator) << endl;
}

Fraction Fraction::add(Fraction b)
{
    Fraction result;

    result.numerator = numerator * b.denominator + denominator * b.numerator;
    result.denominator = denominator * b.denominator;

    return result;
}

Fraction Fraction::substract(Fraction b)
{
    Fraction result;

    result.numerator = numerator * b.denominator - denominator * b.numerator;
    result.denominator = denominator * b.denominator;

    return result;
}

Fraction Fraction::multiply(Fraction b)
{
    Fraction result;

    result.numerator = numerator * b.numerator;
    result.denominator = denominator * b.denominator;

    return result;
}

Fraction Fraction::divide(Fraction b)
{
    if (b.numerator == 0 || b.denominator == 0)
    {
        cout << "Divided by zero, forced exit!!!";
        exit(0);
    }

    Fraction result;

    result.numerator = numerator * b.denominator;
    result.denominator = denominator * b.numerator;

    return result;
}

void Fraction::reduce()
{
    int gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::compare(Fraction b)
{
    float value_a = (float)numerator / (float)denominator;
    float value_b = (float)b.numerator / (float)b.denominator;

    if (value_a > value_b)
        return 1;
    else if (value_a == value_b)
        return 0;
    else
        return -1;
}

bool Fraction::isPositive()
{
    if ((float)numerator / (float)denominator > 0)
        return true;
    return false;
}

bool Fraction::isNegative()
{
    if ((float)numerator / (float)denominator < 0)
        return true;
    return false;
}

bool Fraction::isZero()
{
    if ((float)numerator / (float)denominator == 0)
        return true;
    return false;
}