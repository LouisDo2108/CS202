#include "header.h"

Teacher::Teacher()
    : id(1), name("TBA"), salary_weight(1), basic_salary(5000000), off_count(4),
      salary(salary_weight * basic_salary - off_count * 100000){};

Teacher::Teacher(int id, string name)
    : id(id), name(name), salary_weight(1), basic_salary(5000000), off_count(4),
      salary(salary_weight * basic_salary - off_count * 100000){};

Teacher::Teacher(const Teacher &rhs)
    : id(rhs.id), name(rhs.name), salary_weight(rhs.salary_weight), basic_salary(rhs.basic_salary), off_count(rhs.off_count), salary(rhs.salary){};

Teacher::Teacher(int id, string name, double salary_weight, int basic_salary, int off_count)
    : id(id), name(name), salary_weight(salary_weight), basic_salary(basic_salary), off_count(off_count),
      salary(salary_weight * basic_salary - off_count * 100000){};

Teacher::Teacher(int id, string name, int basic_salary)
    : id(id), name(name), salary_weight(1), basic_salary(basic_salary), off_count(4),
      salary(salary_weight * basic_salary - off_count * 100000){};

void Teacher::input()
{
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary weight: ";
    cin >> salary_weight;
    cout << "Basic salary: ";
    cin >> basic_salary;
    cout << "Off-day count: ";
    cin >> off_count;
    salary = basic_salary * salary_weight - off_count * 100000;
}

void Teacher::output()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary weight: " << salary_weight << endl;
    cout << "Basic salary: " << basic_salary << endl;
    cout << "Off-day count: " << off_count << endl;
    cout << "Salary: " << salary << endl;
}

Homeroom::Homeroom()
    : Teacher(), class_name("TBA")
{
    salary += 150000;
}

Homeroom::Homeroom(const Homeroom &rhs)
    : Teacher(rhs), class_name(rhs.class_name)
{
    salary += 150000;
}

Homeroom::Homeroom(int id, string name, double salary_weight, int basic_salary, int off_count, string class_name)
    : Teacher(id, name, salary_weight, basic_salary, off_count), class_name(class_name)
{
    salary += 150000;
}

Homeroom::Homeroom(int id, string name, string class_name)
    : Teacher(id, name), class_name(class_name)
{
    salary += 150000;
}

Homeroom::Homeroom(int id, string name)
    : Teacher(id, name), class_name(class_name)
{
    salary += 150000;
}

void Homeroom::input()
{
    Teacher::input();
    cout << "Homeroom of class: ";
    cin >> class_name;
    salary += 150000;
}

void Homeroom::output()
{
    cout << "Homeroom teacher of class " << class_name << endl;
    Teacher::output();
}
