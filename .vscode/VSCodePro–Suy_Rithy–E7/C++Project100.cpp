#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z = 1;
    cout << "Diamond Pattern \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    z = n - 1;

    for (x = 1; x <= n; x++)
    {
        for (y = 1; y <= z; y++)
        {
            cout << " ";
        }
        z--;
        for (y = 1; y <= 2 * x - 1; y++)
        {
            cout << "*";
        }
        cout << endl;
    }

    z = 1;

    for (x = 1; x <= n - 1; x++)
    {
        for (y = 1; y <= z; y++)
        {
            cout << " ";
        }
        z++;
        for (y = 1; y <= 2 * (n - x) - 1; y++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}