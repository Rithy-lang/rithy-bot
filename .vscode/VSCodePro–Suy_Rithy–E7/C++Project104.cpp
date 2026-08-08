#include <iostream>

using namespace std;

int main()
{
    int x, y, z = 1, n;
    cout << "Floyd's Triangle \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    for (x = 1; x <= n; x++)
    {
        for (y = 1; y <= x; y++)
        {
            cout << z << " ";
            z++;
        }
        cout << endl;
    }

    return 0;
}