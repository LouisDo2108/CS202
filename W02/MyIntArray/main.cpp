#include "MyIntArray.h"

int main()
{
    cout << "MyIntArray's default constructor: " << endl;
    MyIntArray a;
    a.output();

    int *temp = new int[10]{};

    cout << "MyIntArray's constructor with *a and n as arguments: " << endl;
    MyIntArray b(temp, 10);
    b.output();

    cout << "MyIntArray's constructor with a integer n as argument: " << endl;
    MyIntArray c(5);
    c.output();

    cout << "MyIntArray's constructor with a string as argument" << endl;
    MyIntArray d("1, 2 ,3 ,4 ,5");
    d.output();

    cout << "MyIntArray's copy constructor(Use the previous object)" << endl;
    MyIntArray e(d);
    e.output();

    delete[] temp;
    return 0;
}