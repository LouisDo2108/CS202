#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class Teacher
{
public:
    Teacher();
    Teacher(int id, string name);
    Teacher(const Teacher &rhs);
    Teacher(int id, string name, double salary_weight, int basic_salary, int off_count);
    Teacher(int id, string name, int basic_salary);

    void input();
    void output();

private:
    int id, basic_salary, off_count;
    string name;
    double salary_weight;

protected:
    double salary;
};

class Homeroom : public Teacher
{
public:
    Homeroom();
    Homeroom(const Homeroom &rhs);
    Homeroom(int id, string name, double salary_weight, int basic_salary, int off_count, string class_name);
    Homeroom(int id, string name, string class_room);
    Homeroom(int id, string name);

    void input();
    void output();

private:
    string class_name;
};

#endif