#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class MyIntArray
{
public:
    MyIntArray();
    MyIntArray(int n);
    MyIntArray(const MyIntArray &rhs);
    MyIntArray(int *&a, int n);
    MyIntArray(string exp);
    ~MyIntArray();
    void output();

private:
    int *a;
    int n;
};

#endif