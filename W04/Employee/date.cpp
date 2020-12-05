#include "date.h"

bool Date::isValid()
{
    if (m == 2 && isLeap(y) && d >= 0 && d <= 29)
        return true;
    if (d > 0 && d <= dd[m - 1] && m > 0 && m <= 12 && m != 2)
        return true;
    return false;
}

Date &Date::operator=(const Date &rhs)
{
    d = rhs.d;
    m = rhs.m;
    y = rhs.y;
    return *this;
}

Date Date::Tomorrow()
{
    Date temp(*this);
    if (temp.d == dd[temp.m - 1])
    {
        if (temp.m == 2 && isLeap(temp.y))
            ++temp.d;
        else
        {
            temp.d = 1;
            ++temp.m;
        }

        if (temp.m >= 12)
        {
            temp.m = 1;
            ++temp.y;
        }
    }
    else
        ++temp.d;
    return temp;
}

Date Date::Yesterday()
{
    Date temp(*this);
    if (temp.d == 1)
    {
        if (temp.m == 2 && isLeap(temp.y))
            d = dd[temp.m - 1] + 1;
        else
        {
            temp.d = dd[temp.m - 1];
            --temp.m;
        }

        if (temp.m <= 0)
        {
            temp.m = 12;
            --temp.y;
        }
    }
    else
        --temp.d;
    return temp;
}

bool isLeap(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    return false;
}

bool Date::operator==(const Date &rhs)
{
    return (d == rhs.d && m == rhs.m && y == rhs.y);
}

bool Date::operator!=(const Date &rhs)
{
    return !(*this == rhs);
}

bool Date::operator>=(const Date &rhs)
{
    if (y < rhs.y)
        return false;
    if (m < rhs.m)
        return false;
    if (d < rhs.m)
        return false;
    return true;
}

bool Date::operator>(const Date &rhs)
{
    return !(this->operator<=(rhs));
}

bool Date::operator<=(const Date &rhs)
{
    if (y > rhs.y)
        return false;
    if (m > rhs.m)
        return false;
    if (d > rhs.m)
        return false;
    return true;
}

bool Date::operator<(const Date &rhs)
{
    return !(this->operator>=(rhs));
}

Date operator+(const Date &lhs, const int x)
{
    Date temp(lhs);
    temp += x;
    return temp;
}

Date operator-(const Date &lhs, const int x)
{
    Date temp(lhs);
    temp -= x;
    return temp;
}

Date Date::operator++(int)
{
    Date temp(*this);
    *this = this->Tomorrow();
    return temp;
}

Date &Date::operator++()
{
    *this = this->Tomorrow();
    return *this;
}

Date Date::operator--(int)
{
    Date temp(*this);
    *this = this->Yesterday();
    return temp;
}

Date &Date::operator--()
{
    *this = this->Yesterday();
    return *this;
}

ostream &operator<<(ostream &out, const Date &rhs)
{
    out << rhs.d << "/" << rhs.m << "/" << rhs.y << endl;
    return out;
}

istream &operator>>(istream &in, Date &rhs)
{
    cout << "Enter day: ";
    in >> rhs.d;
    cout << "Enter month: ";
    in >> rhs.m;
    cout << "Enter year: ";
    in >> rhs.y;
    return in;
}

Date::operator int() const
{
    int count = 0;
    for (int i = 0; i < (m - 1); ++i)
        count += dd[m - 1];
    count += d;
    if (isLeap(y) && m > 2)
        ++count;
    return count;
}

Date::operator long() const
{
    int count = 0, i;
    for (i = 0; i < y; ++i)
    {
        count += 365;
        if (isLeap(i))
            ++count;
    }
    count += (int)*this;
    return count;
}

Date &Date::operator+=(const int x)
{
    d += x;
    while (d > dd[m - 1])
    {
        d -= dd[m - 1];
        if (isLeap(y) && m == 2)
            --d;
        ++m;

        if (m > 12)
        {
            m = 1;
            ++y;
        }
    }
    return *this;
}

Date &Date::operator-=(const int x)
{
    d -= x;
    while (d < 0)
    {
        d += dd[m - 1];
        if (isLeap(y) && m == 2)
            ++d;
        --m;

        if (m < 1)
        {
            m = 12;
            --y;
        }
    }
    return *this;
}
