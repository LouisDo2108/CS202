#include "Student.h"

Student::Student()
    : id(-1),
      fullname(nullptr),
      address(nullptr),
      gpa(0) {}

Student::Student(int id, char *fullname, char *address, double gpa)
    : id(id), gpa(gpa)
{
    this->fullname = new char[strlen(fullname) + 1];
    this->address = new char[strlen(address) + 1];

    strcpy(this->fullname, fullname);
    strcpy(this->address, address);
}

Student::Student(const Student &rhs)
{
    id = rhs.id;
    fullname = new char[strlen(rhs.fullname) + 1];
    address = new char[strlen(rhs.address) + 1];
    strcpy(fullname, rhs.fullname);
    strcpy(address, rhs.address);
    gpa = rhs.gpa;
}

Student::Student(char *fullname)
{
    id = -1;
    this->fullname = new char[strlen(fullname) + 1];
    strcpy(this->fullname, fullname);
    address = new char[strlen("TBA") + 1];
    strcpy(address, "TBA");
    gpa = 0;
}

Student::Student(string exp)
{
    int i = 0;
    string tmp;

    while (exp[i] != ',')
        tmp += exp[i++];
    i += 2;
    id = stoi(tmp);
    tmp = "";

    while (exp[i] != ',')
        tmp += exp[i++];
    i += 2;
    fullname = new char[tmp.length() + 1];
    strcpy(fullname, tmp.c_str());
    tmp = "";

    while (exp[i] != ',')
        tmp += exp[i++];
    i += 2;
    address = new char[tmp.length() + 1];
    strcpy(address, tmp.c_str());
    tmp = "";

    while (exp[i] != ',')
        tmp += exp[i++];
    gpa = stod(tmp);
}

Student::~Student()
{
    if (fullname)
        delete[] fullname;
    if (address)
        delete[] address;
}

void Student::output()
{
    cout << id << ", ";
    if (fullname)
        cout << fullname;
    else
        cout << "TBA";
    cout << ", ";
    if (address)
        cout << address;
    else
        cout << "TBA";
    cout << ", ";
    cout << gpa << endl;
}