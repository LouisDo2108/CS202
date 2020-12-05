#ifndef header
#define header

#include <iostream>

using namespace std;

class IntArray
{
public:
    IntArray();
    IntArray(const int n);
    IntArray(const int a[], const int n);
    IntArray(const IntArray &rhs);
    ~IntArray();

    int &operator[](const int n);
    IntArray &operator=(IntArray rhs);

    friend istream &operator>>(istream &in, IntArray &rhs);
    friend ostream &operator<<(ostream &out, const IntArray &rhs);

    explicit operator int() const
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i];
        return sum;
    }

private:
    int *arr, n;
};

#endif