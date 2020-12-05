#include "header.h"
#include "date.h"

int main()
{
    Company abc;
    int id;
    string name;

    abc.input();
    cout << endl;

    abc.output();
    cout << endl;

    cout << "abc company total salary: " << abc.totalSalary() << endl;
    cout << endl;

    cout << "abc company's highest salary employee: ";
    abc.maxSalary();
    cout << endl;

    cout << "abc company production employee count: " << abc.pCount() << endl;
    cout << endl;

    cout << "abc company day employee count: " << abc.dCount() << endl;
    cout << endl;

    cout << "abc company average salary: " << abc.avgSalary() << endl;
    cout << endl;

    cout << "abc company's employees with under 3 millions salary: " << endl;
    abc.listUnder3();
    cout << endl;

    cout << "Search for employee via ID: ";
    cin >> id;
    abc.searchID(id);
    cout << endl;

    cout << "Search for employee via name: ";
    cin >> name;
    abc.searchName(name);
    cout << endl;

    cout << "abc company number of employee with date of birth is May: " << abc.countDOB5() << endl;

    return 0;
}