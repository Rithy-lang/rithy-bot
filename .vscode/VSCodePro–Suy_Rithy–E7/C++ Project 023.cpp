#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cout << "How to swap Numbers using three variables \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    cout << "Numbers before swapping are : " << x << " and " << y << endl;

    z = x;
    x = y;
    y = z;

    cout << "Numbers after swapping are : " << x << " and " << y << endl;

    return 0;
}