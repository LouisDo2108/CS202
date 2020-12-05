#include "Lecturer.h"

int main()
{
    cout << "Lecturer's default constructor: " << endl;
    Lecturer a;
    a.output();

    cout << "Lecturer's constructor with full arguments: " << endl;
    Lecturer b(1, "Nguyen Van A", "BSc", 40);
    b.output();

    cout << "Lecturer's constructor with id and fullname as arguments: " << endl;
    Lecturer c(2, "Le Van B");
    c.output();

    cout << "Lecturer's with a string as argument: " << endl;
    Lecturer d(3, "Tran Van C", "Ph.D", 120);
    d.output();

    cout << "Lecturer's copy constructor(Use the previous object): " << endl;
    Lecturer e(d);
    e.output();
    return 0;
}