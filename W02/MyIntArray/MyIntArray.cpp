#include "MyIntArray.h"

MyIntArray::MyIntArray()
{
    a = nullptr;
    n = 0;
}

MyIntArray::MyIntArray(int n)
    : n(n)
{
    a = new int[n]{};
}

MyIntArray::MyIntArray(string exp)
{
    string tmp;
    int counter = 0;
    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
        {
            while (exp[i] >= 48 && exp[i] <= 57)
                ++i;
            ++counter;
        }
    }

    n = counter;
    a = new int[counter];
    counter = 0;

    for (int i = 0; i < exp.length(); ++i)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
        {
            while (exp[i] >= 48 && exp[i] <= 57)
                tmp += exp[i++];
            a[counter++] = stoi(tmp);
            tmp = "";
        }
    }
}

MyIntArray::MyIntArray(int *&a, int n) : n(n)
{
    this->a = new int[n];
    for (int i = 0; i < n; ++i)
        this->a[i] = a[i];
}

MyIntArray::MyIntArray(const MyIntArray &rhs)
{
    n = rhs.n;
    a = new int[n];
    for (int i = 0; i < n; ++i)
        a[i] = rhs.a[i];
}

MyIntArray::~MyIntArray()
{
    if (a)
        delete[] a;
}

void MyIntArray::output()
{
    if (n == 0 || !a)
    {
        cout << "Array is empty" << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << ",";
    cout << endl;
}