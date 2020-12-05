#include "ColorPixel.h"

ColorPixel::ColorPixel()
    : red(255),
      green(255),
      blue(255) {}

ColorPixel::ColorPixel(int r, int g, int b)
    : red(r),
      green(g),
      blue(b) {}

ColorPixel::ColorPixel(const ColorPixel &rhs)
    : red(rhs.red),
      green(rhs.green),
      blue(rhs.blue) {}

ColorPixel::ColorPixel(int rgb)
    : red(rgb),
      green(rgb),
      blue(rgb) {}

ColorPixel::ColorPixel(string exp)
{
    string r, g, b;
    int i = 0;

    while (exp[i] >= 48 && exp[i] <= 57)
        r += exp[i++];
    while (!(exp[i] >= 48 && exp[i] <= 57))
        ++i;
    while (exp[i] >= 48 && exp[i] <= 57)
        g += exp[i++];
    while (!(exp[i] >= 48 && exp[i] <= 57))
        ++i;
    while (exp[i] >= 48 && exp[i] <= 57)
        b += exp[i++];

    red = stoi(r);
    green = stoi(g);
    blue = stoi(b);
}

void ColorPixel::output()
{
    if (red > 255 || green > 255 || blue > 255)
        cout << "Color channel's value can't be greater than 255" << endl;
    else
        cout << red << ", " << green << ", " << blue << endl;
}