#include <iostream>

using namespace std;

int main()
{
    int x, y, z, sum = 0;
    cout << "Adding N Numbers \n"
         << endl;

    cout << "Please choose range of number to add: " << endl;
    cin >> x;

    cout << "Please insert " << x << " number(s) only: " << endl;

    for (y = 1; y <= x; y++)
    {
        cin >> z;
        sum = sum + z;
    }

    cout << "The result of addition of " << x << " number(s) is = " << sum << endl;

    return 0;
}