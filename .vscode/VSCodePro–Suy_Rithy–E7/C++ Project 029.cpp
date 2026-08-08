#include <iostream>

using namespace std;

int HCF(int x, int y);

int main()
{
    int x, y;

    cout << "Calculate HCF using recursive function \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    cout << "The HCH of " << x << " and " << y << " is " << HCF(x, y);

    return 0;
}

int HCF(int x, int y)
{
    if (y != 0)
        return HCF(y, x % y);
    else
        return x;
}