#ifndef header_emp
#define header_emp

#include <iostream>
#include <string>
#include <vector>

#include "date.h"

using namespace std;

class Emp
{
public:
    Emp();
    Emp(const int id, const string name, const Date date, const string address);
    Emp(const int id, const string name);
    Emp(const Emp &rhs);
    Emp(const string name, const Date date);

    virtual ~Emp(){};

    virtual void output();
    virtual void input();
    double getSalary();
    int getID();
    string getName();
    Date getDate();

private:
    int id;
    string name;
    Date date;
    string address;

protected:
    double salary;
};

class ProEmp : public Emp
{
public:
    ProEmp();
    ProEmp(const int id, const string name);
    ProEmp(const int id, const string name, const Date date, const string address);
    ProEmp(const int id, const string name, const Date date, const string address, int productCount);
    ProEmp(const ProEmp &rhs);
    void input();
    void output();

private:
    int productCount;
};

class dayEmp : public Emp
{
public:
    dayEmp();
    dayEmp(const int id, const string name);
    dayEmp(const int id, const string name, const Date date, const string address);
    dayEmp(const int id, const string name, const Date date, const string address, int dayCount);
    dayEmp(const dayEmp &rhs);
    void input();
    void output();

private:
    int dayCount;
};

class Company
{
public:
    Company() : emp_list(), productionEmpCount(0), dayEmpCount(0){};
    void input();
    void output();
    double totalSalary();
    void maxSalary();
    int pCount();
    int dCount();
    double avgSalary();
    void listUnder3();
    void searchID(int id);
    void searchName(string name);
    int countDOB5();

private:
    vector<Emp *> emp_list;
    int productionEmpCount;
    int dayEmpCount;
};

#endif
