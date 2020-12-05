#include "mydate.h"

int main()
{
    cout << "My date's default constructor: " << endl;
    MyDate a;
    a.output();

    cout << "My date's constructor with dmy as arguments: " << endl;
    MyDate b(21, 8, 2001);
    b.output();

    cout << "My date's constructor with y as argument: " << endl;
    MyDate c(2001);
    c.output();

    cout << "My date's constructor with my as arguments: " << endl;
    MyDate d(8, 2001);
    d.output();

    cout << "My date's constructor with a string as argument: " << endl;
    MyDate e("21/08/2001");
    e.output();
    return 0;
}