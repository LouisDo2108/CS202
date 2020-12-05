#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class MyDate
{
public:
    MyDate();
    MyDate(int d, int m, int y);
    MyDate(int y);
    MyDate(int m, int y);
    MyDate(string exp);
    void output();

private:
    int day, month, year;
};

#endif