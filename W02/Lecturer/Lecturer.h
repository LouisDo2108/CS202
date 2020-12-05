#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class Lecturer
{
public:
    Lecturer();
    Lecturer(int id, string fullname, string degree, int num_course);
    Lecturer(const Lecturer &rhs);
    Lecturer(string exp);
    Lecturer(int id, string fullname);
    void output();

private:
    int id, num_course;
    string fullname, degree;
};

#endif