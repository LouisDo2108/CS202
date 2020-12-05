#include "ColorPixel.h"

int main()
{
    cout << "ColorPixel's default constructor: " << endl;
    ColorPixel a;
    a.output();

    cout << "ColorPixel's constructor with r, g, b as arguments: " << endl;
    ColorPixel b(255, 0, 255);
    b.output();

    cout << "ColorPixel's constructor with a string as argument: " << endl;
    ColorPixel c("123, 123, 123");
    c.output();

    cout << "ColorPixel's constructor with rgb as argument: " << endl;
    ColorPixel d(100);
    d.output();

    cout << "ColorPixel's constructor with a ColorPixel object as argument(Use the previous object): " << endl;
    ColorPixel e(d);
    e.output();
    return 0;
}