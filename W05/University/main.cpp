#include "header.h"

int main()
{
    School a;
    int id;
    string name;

    a.input();
    cout << endl;

    a.output();
    cout << endl;

    cout << "Total salary: " << a.totalSalary() << endl;
    cout << endl;

    cout << "Max salary:" << endl;
    a.maxSalary();
    cout << endl;

    cout << "Number of non-homeroom teachers: " << a.tCount() << endl;
    cout << endl;

    cout << "Number of homeroom teachers: " << a.hCount() << endl;
    cout << endl;

    cout << "Average salary: " << a.avgSalary() << endl;
    cout << endl;

    cout << "List of teacher that has over 10 millions VND salary:" << endl;
    a.listOver10();
    cout << endl;

    cout << "Search a teacher via id: ";
    cin >> id;
    a.searchID(id);
    cout << endl;

    cout << "Search a teacher via name: ";
    cin >> name;
    a.searchName(name);
    cout << endl;

    cout << "Number of teachers who has over 4 days off: " << a.offOver4() << endl;

    return 0;
}