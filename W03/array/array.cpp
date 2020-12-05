#include "array.h"

IntArray::IntArray() : n(0), arr(nullptr){};

IntArray::IntArray(const int n) : n(n), arr(new int[n]{}){};

IntArray::IntArray(const int a[], const int n) : n(n)
{
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = a[i];
}

IntArray::IntArray(const IntArray &rhs)
{
    n = rhs.n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rhs.arr[i];
}

IntArray::~IntArray()
{
    if (arr)
        delete[] arr;
}

int &IntArray::operator[](const int n)
{
    return arr[n];
}

IntArray &IntArray::operator=(IntArray rhs)
{
    swap(n, rhs.n);
    swap(arr, rhs.arr);
    return *this;
}

istream &operator>>(istream &in, IntArray &rhs)
{
    int i;
    for (i = 0; i < rhs.n; ++i)
    {
        cout << "Arr[" << i << "]: ";
        in >> rhs.arr[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const IntArray &rhs)
{
    if (rhs.arr && rhs.n > 0)
    {
        for (int i = 0; i < rhs.n; ++i)
            out << rhs.arr[i] << ", ";
    }
    else
        out << "IntArray is empty!";
    out << endl;
    return out;
}
