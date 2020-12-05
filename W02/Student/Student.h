#ifndef header
#define header

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Student
{
public:
    Student();
    Student(int id, char *fullname, char *address, double gpa);
    Student(const Student &rhs);
    Student(char *fullname);
    Student(string exp);

    void output();

    ~Student();

private:
    int id;
    char *fullname;
    char *address;
    double gpa;
};

#endif
