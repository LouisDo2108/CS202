#ifndef header
#define header

#include <iostream>
#include <string>

using namespace std;

class ColorPixel
{
public:
    ColorPixel();
    ColorPixel(int r, int g, int b);
    ColorPixel(string exp);
    ColorPixel(const ColorPixel &rhs);
    ColorPixel(int rgb);
    void output();

private:
    int red, green, blue;
};

#endif