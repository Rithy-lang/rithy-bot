#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cout << "Swap Numbers using two variables \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    cout << "Numbers before swapping are: " << x << " and " << y << endl;

    x = x + y;
    y = x - y;
    x = x - y;

    cout << "Numbers after swapping are: " << x << " and " << y << endl;

    return 0;
}