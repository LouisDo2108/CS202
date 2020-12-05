#ifndef header
#define header

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Teacher
{
public:
    Teacher();
    Teacher(int id, string name);
    Teacher(const Teacher &rhs);
    Teacher(int id, string name, double salary_weight, int basic_salary, int off_count);
    Teacher(int id, string name, int basic_salary);

    double getSalary();
    int getID();
    string getName();
    int getOffCount();

    virtual void input();
    virtual void output();

    virtual ~Teacher(){};

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

class School
{
public:
    School() : teacherCount(0), homeroomCount(0){};

    void input();
    void output();
    double totalSalary();
    void maxSalary();
    int tCount();
    int hCount();
    double avgSalary();
    void listOver10();
    void searchID(int id);
    void searchName(string name);
    int offOver4();

private:
    int teacherCount, homeroomCount;
    vector<Teacher *> teacher_list;
};

#endif