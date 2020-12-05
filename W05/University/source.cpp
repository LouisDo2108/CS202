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

double Teacher::getSalary()
{
    return salary;
}

int Teacher::getID()
{
    return id;
}

string Teacher::getName()
{
    return name;
}

int Teacher::getOffCount()
{
    return off_count;
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

void School::input()
{
    int n, type;
    Teacher *p;
    cout << "Enter the number of teachers: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        p = nullptr;
        cout << "Inputing teacher number: " << i << endl;
        cout << "Teacher type(0. Normal; 1. Homeroom): ";
        cin >> type;

        if (type == 0)
        {
            p = new Teacher;
            ++teacherCount;
        }
        else if (type == 1)
        {
            p = new Homeroom;
            ++homeroomCount;
        }
        else
        {
            --i;
            cout << "Invalid type!" << endl;
            continue;
        }
        p->input();
        teacher_list.push_back(p);
    }
}

void School::output()
{
    cout << "List of school's teachers:" << endl;
    int size = teacher_list.size();
    for (int i = 0; i < size; ++i)
    {
        teacher_list[i]->output();
        cout << endl;
    }
}

double School::totalSalary()
{
    int sum = 0;
    int size = teacher_list.size();
    for (int i = 0; i < size; ++i)
        sum += teacher_list[i]->getSalary();
    return sum;
}

void School::maxSalary()
{
    int size = teacher_list.size(), max = 0;

    for (int i = 1; i < size; ++i)
        if (teacher_list[i]->getSalary() > teacher_list[max]->getSalary())
            max = i;

    teacher_list[max]->output();
    return;
}

int School::tCount()
{
    return teacherCount;
}

int School::hCount()
{
    return homeroomCount;
}

double School::avgSalary()
{
    return totalSalary() / teacher_list.size();
}

void School::listOver10()
{
    bool flag = true;
    int size = teacher_list.size();

    for (int i = 0; i < size; ++i)
    {
        if (teacher_list[i]->getSalary() > 10000000)
        {
            teacher_list[i]->output();
            flag = false;
        }
    }

    if (flag)
        cout << "None" << endl;
    return;
}

void School::searchID(int id)
{
    int size = teacher_list.size();
    for (int i = 0; i < size; ++i)
    {
        if (teacher_list[i]->getID() == id)
        {
            teacher_list[i]->output();
            return;
        }
    }
    cout << "Can't find the teacher with id: " << id << endl;
    return;
}

void School::searchName(string name)
{
    int size = teacher_list.size();
    for (int i = 0; i < size; ++i)
    {
        if (teacher_list[i]->getName() == name)
        {
            teacher_list[i]->output();
            return;
        }
    }
    cout << "Can't find the teacher with name: " << name << endl;
    return;
}

int School::offOver4()
{
    int count = 0, size = teacher_list.size();

    for (int i = 0; i < size; ++i)
        if (teacher_list[i]->getOffCount() > 4)
            ++count;
    return count;
}