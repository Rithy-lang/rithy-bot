#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n;
    cout << "Pyramid Pattern \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    z = n;

    for (x = 1; x <= n; x++)
    {
        for (y = 1; y < z; y++)
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

    return 0;
}