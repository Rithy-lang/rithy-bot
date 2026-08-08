#include <iostream>

using namespace std;

int main()
{
    int x, y, n, k = 0, cnt = 0, cnt1 = 0;
    cout << "Numeric Pyramid Pattern \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> n;

    for (x = 1; x <= n; ++x)
    {
        for (y = 1; y <= n - x; ++y)
        {
            cout << " ";
            ++cnt;
        }

        while (k != 2 * x - 1)
        {
            if (cnt <= n - 1)
            {
                cout << x + k << " ";
                ++cnt;
            }
            else
            {
                ++cnt1;
                cout << x + k - 2 * cnt1 << " ";
            }
            ++k;
        }
        cnt1 = cnt = k = 0;
        cout << endl;
    }

    return 0;
}