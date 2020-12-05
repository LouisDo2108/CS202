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

double Emp::getSalary()
{
    return salary;
}

int Emp::getID()
{
    return id;
}

string Emp::getName()
{
    return name;
}

Date Emp::getDate()
{
    return date;
}

void Emp::output()
{
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

void Company::input()
{
    int n;
    int type;
    Emp *p;
    cout << "Enter the number of employee: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "Inputing employee number " << i + 1 << endl;
        cout << "Employee type (1 for Product Employee; 2 for Day Employee): ";
        cin >> type;

        p = nullptr;

        if (type == 1)
        {
            p = new ProEmp;
            ++productionEmpCount;
        }
        else if (type == 2)
        {
            p = new dayEmp;
            ++dayEmpCount;
        }
        else
        {
            --i;
            cout << "Invalid type!" << endl;
            continue;
        }
        p->input();
        emp_list.push_back(p);
    }
}

void Company::output()
{
    cout << "List of company employee:" << endl;
    int size = emp_list.size();
    for (int i = 0; i < size; ++i)
    {
        emp_list[i]->output();
        cout << endl;
    }
}

double Company::totalSalary()
{
    double sum = 0;
    int size = emp_list.size();
    for (int i = 0; i < size; ++i)
        sum += emp_list[i]->getSalary();
    return sum;
}

void Company::maxSalary()
{
    double max = 0;
    int size = emp_list.size();

    for (int i = 1; i < size; ++i)
        if (emp_list[i]->getSalary() > emp_list[max]->getSalary())
            max = i;

    emp_list[max]->output();
}

int Company::pCount()
{
    return productionEmpCount;
}

int Company::dCount()
{
    return dayEmpCount;
}

double Company::avgSalary()
{
    double total = totalSalary();
    return total / emp_list.size();
}

void Company::listUnder3()
{
    bool flag = true;
    int size = emp_list.size();
    for (int i = 0; i < size; ++i)
    {
        if (emp_list[i]->getSalary() < 3000000)
        {
            emp_list[i]->output();
            cout << endl;
            flag = false;
        }
    }
    if (flag)
        cout << "NONE" << endl;
}

void Company::searchID(int id)
{
    int size = emp_list.size();
    for (int i = 0; i < size; ++i)
    {
        if (emp_list[i]->getID() == id)
        {
            emp_list[i]->output();
            return;
        }
    }
    cout << "There is no employee with id: " << id << endl;
}

void Company::searchName(string name)
{
    int size = emp_list.size();
    for (int i = 0; i < size; ++i)
    {
        if (emp_list[i]->getName() == name)
        {
            emp_list[i]->output();
            return;
        }
    }
    cout << "There is no employee with name: " << name << endl;
}

int Company::countDOB5()
{
    int size = emp_list.size();
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (emp_list[i]->getDate().getMonth() == 5)
            ++count;
    return count;
};
