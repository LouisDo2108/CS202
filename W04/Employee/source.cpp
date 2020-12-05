#include "header.h"

Emp::Emp()
{
    id = 1;
    name = "TBA";
    Date temp;
    date = temp;
    address = "TBA";
}

Emp::Emp(const int id, const string name, const Date date, const string address)
{
    this->id = id;
    this->name = name;
    this->date = date;
    this->address = address;
}

Emp::Emp(const int id, const string name)
{
    this->id = id;
    this->name = name;
    Date temp;
    date = temp;
    address = "TBA";
}

Emp::Emp(const Emp &rhs)
{
    id = rhs.id;
    name = rhs.name;
    date = rhs.date;
    address = rhs.address;
}

Emp::Emp(const string name, const Date date)
{
    id = 0;
    this->name = name;
    this->date = date;
    address = "TBA";
}

void Emp::output()
{
    cout << "Employee info: " << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Day of birth : ";
    cout << date;
    cout << "Address: " << address << endl;
}

void Emp::input()
{
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Date: " << endl;
    cin >> date;
    cout << "Address: ";
    cin >> address;
}

ProEmp::ProEmp() : Emp(), productCount(0){};

ProEmp::ProEmp(const int id, const string name) : Emp(id, name), productCount(0){};

ProEmp::ProEmp(const int id, const string name, const Date date, const string address)
    : Emp(id, name, date, address), productCount(0){};

ProEmp::ProEmp(const int id, const string name, const Date date, const string address, int productCount)
    : Emp(id, name, date, address), productCount(productCount){};

ProEmp::ProEmp(const ProEmp &rhs) : Emp(rhs), productCount(rhs.productCount){};

void ProEmp::input()
{
    Emp::input();
    cout << "Product count: ";
    cin >> productCount;
    salary = productCount * 20000;
}

void ProEmp::output()
{
    cout << "Production employee: " << endl;
    Emp::output();
    cout << "Salary: " << salary << endl;
}

dayEmp::dayEmp() : Emp(), dayCount(0){};

dayEmp::dayEmp(const int id, const string name) : Emp(id, name), dayCount(0){};

dayEmp::dayEmp(const int id, const string name, const Date date, const string address)
    : Emp(id, name, date, address), dayCount(0){};

dayEmp::dayEmp(const int id, const string name, const Date date, const string address, int dayCount)
    : Emp(id, name, date, address), dayCount(dayCount){};

dayEmp::dayEmp(const dayEmp &rhs)
    : Emp(rhs), dayCount(dayCount){};

void dayEmp::input()
{
    Emp::input();
    cout << "Day count: ";
    cin >> dayCount;
    salary = dayCount * 300000;
}

void dayEmp::output()
{
    cout << "Daily paid employee: " << endl;
    Emp::output();
    cout << "Salary: " << salary << endl;
}
