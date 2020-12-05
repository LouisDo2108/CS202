#ifndef header
#define header

#include <iostream>

using namespace std;

const int dd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
public:
    Date() : y(2020), m(11), d(7){};
    Date(int y) : y(y), m(1), d(1){};
    Date(int y, int m) : y(y), m(m), d(1){};
    Date(int y, int m, int d) : y(y), m(m), d(d){};
    Date(const Date &rhs) : d(rhs.d), m(rhs.m), y(rhs.y){};

    int getMonth();

    bool isValid();

    Date &operator=(const Date &rhs);
    Date Tomorrow();
    Date Yesterday();

    bool operator==(const Date &rhs);
    bool operator!=(const Date &rhs);
    bool operator>=(const Date &rhs);
    bool operator<=(const Date &rhs);
    bool operator>(const Date &rhs);
    bool operator<(const Date &rhs);

    friend Date operator+(const Date &lhs, const int x);
    friend Date operator-(const Date &lhs, const int x);

    Date operator++(int);
    Date &operator++();
    Date operator--(int);
    Date &operator--();

    friend ostream &operator<<(ostream &out, const Date &rhs);
    friend istream &operator>>(istream &in, Date &rhs);

    explicit operator int() const;
    explicit operator long() const;

    Date &operator+=(const int x);
    Date &operator-=(const int x);

private:
    int d, m, y;
};

bool isLeap(int y);

#endif