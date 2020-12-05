#include "Lecturer.h"

Lecturer::Lecturer()
    : id(-1),
      fullname("TBA"),
      degree("TBA"),
      num_course(0) {}

Lecturer::Lecturer(int id, string fullname, string degree, int num_course)
    : id(id),
      fullname(fullname),
      degree(degree),
      num_course(num_course) {}

Lecturer::Lecturer(const Lecturer &rhs)
    : id(rhs.id),
      fullname(rhs.fullname),
      degree(rhs.degree),
      num_course(rhs.num_course) {}

Lecturer::Lecturer(int id, string fullname)
    : id(id), fullname(fullname)
{
    degree = "TBA";
    num_course = 0;
}

Lecturer::Lecturer(string exp)
{
    int i = 0;
    string idd, fn, dg, num;

    while (exp[i] != ',')
        idd += exp[i++];
    i += 2;

    while (exp[i] != ',')
        fn += exp[i++];
    i += 2;

    while (exp[i] != ',')
        dg += exp[i++];
    i += 2;

    while (exp[i] != ',')
        num += exp[i++];
    i += 2;

    id = stoi(idd);
    fullname = fn;
    degree = dg;
    num_course = stoi(num);
}

void Lecturer::output()
{
    cout << id << ", " << fullname << ", " << degree << ", " << num_course << endl;
}