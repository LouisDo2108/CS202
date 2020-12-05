#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class MyTime
{
public:
    MyTime();
    MyTime(int h, int m, int s);
    MyTime(int h);
    MyTime(const MyTime &rhs);
    MyTime(string exp);
    void output();

private:
    int hour, minute, second;
};

#endif