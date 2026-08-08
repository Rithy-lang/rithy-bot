#include <iostream>

using namespace std;

int main()
{
    float base, height, area;
    cout << "Area of Triangle \n"
         << endl;

    cout << "Insert height of triangle: " << endl;
    cin >> height;

    cout << "Insert base of triangle: " << endl;
    cin >> base;

    area = (base / 2) * height;

    cout << "The area of the given triangle = " << area << endl;

    return 0;
}