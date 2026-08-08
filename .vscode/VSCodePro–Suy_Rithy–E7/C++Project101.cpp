#include <iostream>

using namespace std;

int main()
{
    int x, y, n;
    cout << "Numeric Right Angle Triangle \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    for (x = 1; x <= n; ++x)
    {
        for (y = 1; y <= x; ++y)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}