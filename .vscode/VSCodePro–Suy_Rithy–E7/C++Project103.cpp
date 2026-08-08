#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n, num = 1;
    cout << "Paschal Triangle \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    for (x = 0; x < n; x++)
    {
        for (y = 1; y <= n - x; y++)
        {
            cout << " ";
        }

        for (z = 0; z <= x; z++)
        {
            if (z == 0 || x == 0)
            {
                num = 1;
            }
            else
            {
                num = num * (x - z + 1) / z;
            }
            cout << " " << num;
        }
        cout << endl;
    }

    return 0;
}