#include <iostream>

using namespace std;

void ref_swap(int &x, int &y);

int main()
{
    int x, y;
    cout << "Call by Reference \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    cout << "Numbers before swapping are: " << x << " and " << y << endl;

    ref_swap(x, y);

    cout << "Numbers after swapping are: " << x << " and " << y << endl;

    return 0;
}

void ref_swap(int &x, int &y)
{
    int z;

    z = x;
    x = y;
    y = z;

    return;
}