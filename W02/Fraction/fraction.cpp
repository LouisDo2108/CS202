#include "fraction.h"

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(const int n)
{
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(const int n, const int d)
{
    if (d == 0)
    {
        cout << "Denominator can't be 0" << endl;
        exit(0);
    }
    numerator = n;
    denominator = d;
}

Fraction::Fraction(string exp)
{
    string nu, de;
    int i;

    for (i = 0; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
            nu += exp[i];
        else
            break;
    }

    for (i = i + 1; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
            de += exp[i];
        else
            break;
    }

    if (stoi(de) == 0)
    {
        cout << "Denominator can't be 0" << endl;
        exit(0);
    }

    numerator = stoi(nu);
    denominator = stoi(de);
}

Fraction::Fraction(const Fraction &rhs)
{
    numerator = rhs.numerator;
    denominator = rhs.denominator;
}

void Fraction::output()
{
    cout << numerator << "/" << denominator << " = " << (float)numerator / (float)(denominator) << endl;
}