#include <iostream>

using namespace std;

int main()
{
    int x, y, n;
    cout << "Right Angle Triangle \n"
         << endl;

    cout << "Insert number of rows of triangle: " << endl;
    cin >> n;

    for (x = 1; x <= n; ++x)
    {
        for (y = 1; y <= x; ++y)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}