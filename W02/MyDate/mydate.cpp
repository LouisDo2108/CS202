#include "mydate.h"

MyDate::MyDate()
{
    day = 1;
    month = 1;
    year = 1900;
}

MyDate::MyDate(int d, int m, int y)
{
    if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 0)
    {
        year = y;
        month = m;
        day = d;
    }
    else
    {
        cout << "Invalid input!" << endl;
        exit(0);
    }
}

MyDate::MyDate(int y)
{
    if (y >= 0)
    {
        year = y;
        month = 1;
        day = 1;
    }
    else
    {
        cout << "Invalid input!" << endl;
        exit(0);
    }
}

MyDate::MyDate(int m, int y)
{
    if (m >= 1 && m <= 12 && y >= 0)
    {
        year = y;
        month = m;
        day = 1;
    }
    else
    {
        cout << "Invalid input!" << endl;
        exit(0);
    }
}

MyDate::MyDate(string exp)
{
    string d, m, y;
    int i = 0;

    while (exp[i] >= 48 && exp[i] <= 57)
    {
        d += exp[i];
        ++i;
    }
    ++i;

    while (exp[i] >= 48 && exp[i] <= 57)
    {
        m += exp[i];
        ++i;
    }
    ++i;

    while (exp[i] >= 48 && exp[i] <= 57)
    {
        y += exp[i];
        ++i;
    }

    if (stoi(d) >= 1 && stoi(d) <= 31 && stoi(m) >= 1 && stoi(m) <= 12 && stoi(y) >= 0)
    {
        year = stoi(y);
        month = stoi(m);
        day = stoi(d);
    }
    else
    {
        cout << "Invalid input!" << endl;
        exit(0);
    }
}

void MyDate::output()
{
    cout << day << "/" << month << "/" << year << endl;
}