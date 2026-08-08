#include <iostream>

using namespace std;

int main()
{
    int x, y, maxi;
    cout << "Calculate LCM \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    maxi = (x > y) ? x : y;

    while (true)
    {
        if (maxi % x == 0 && maxi % y == 0)
        {
            cout << "The LCM of " << x << " and " << y << " = " << maxi << endl;
            break;
        }
        else
        {
            maxi++;
        }
    }

    return 0;
}