#include "mytime.h"

MyTime::MyTime()
    : hour(0),
      minute(0),
      second(0)
{
}

MyTime::MyTime(int h, int m, int s)
    : hour(h),
      minute(m),
      second(s)
{
}

MyTime::MyTime(int h)
    : hour(h),
      minute(0),
      second(0)
{
}

MyTime::MyTime(const MyTime &rhs)
    : hour(rhs.hour),
      minute(rhs.minute),
      second(rhs.second)
{
}

MyTime::MyTime(string exp)
{
    string h, m, s;
    int i = 0;

    while (exp[i] >= 48 && exp[i] <= 57)
        h += exp[i++];
    ++i;
    while (exp[i] >= 48 && exp[i] <= 57)
        m += exp[i++];
    ++i;
    while (exp[i] >= 48 && exp[i] <= 57)
        s += exp[i++];
    ++i;

    hour = stoi(h);
    minute = stoi(m);
    second = stoi(s);
}

void MyTime::output()
{
    cout << hour << ":";
    if (minute < 10)
        cout << "0";
    cout << minute << ":";
    if (second < 10)
        cout << "0";
    cout << second << endl;
}
