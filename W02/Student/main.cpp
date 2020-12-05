#include "Student.h"

int main()
{
    cout << "Student's default constructor: " << endl;
    Student a;
    a.output();

    char tmpName[] = "Nguyen Van A";
    char tmpNameB[] = "Le Van B";
    char tmpAddress[] = "1 Park Avenue NYC";
    cout << "Student's constructor with full arguments: " << endl;
    Student b(1, tmpName, tmpAddress, 3.5);
    b.output();

    cout << "Student's constructor with fullname as argument: " << endl;
    Student c(tmpNameB);
    c.output();

    cout << "Student's constructor with a string as argument: " << endl;
    Student d((string) "2, Tran Van C, 15 Central Park NYC, 4.0");
    d.output();

    cout << "Student's copy constructor (Use the previous object): " << endl;
    Student e(d);
    e.output();
    return 0;
}