#include "triangle.h"

int main()
{
    Point a, b(1), c(1, 2);

    cout << "Triangle default constructor: " << endl;
    Triangle alpha;
    alpha.output();

    cout << "Triangle constructor with two points as argument: " << endl;
    Triangle beta(b, c);
    beta.output();

    cout << "Triangle constructor with three points as argument: " << endl;
    Triangle gamma(a, b, c);
    gamma.output();

    cout << "Triangle constructor with three integers as argument: " << endl;
    Triangle delta(1, 2, 3);
    delta.output();

    cout << "Triangle constructor with a triangle object as argument(Use the previous triangle): " << endl;
    Triangle epsilon(delta);
    epsilon.output();
    return 0;
}