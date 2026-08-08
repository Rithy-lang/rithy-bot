#include <iostream>

using namespace std;

class Area
{
public:
    int length;
    int breadth;
};

int main()
{
    Area A;
    int area;
    cout << "Simple class creations \n"
         << endl;

    cout << "Insert the length of the rectangle: " << endl;
    cin >> A.length;

    cout << "Insert the breadth of the rectangle: " << endl;
    cin >> A.breadth;

    area = A.length * A.breadth;
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}