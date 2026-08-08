#include <iostream>

using namespace std;

int main()
{
    int x, cnt = 0;
    cout << "Check Prime Numbers \n"
         << endl;

    cout << "Insert any number to check for Prime number: " << endl;
    cin >> x;

    for (int y = 1; y <= x; y++)
    {
        if (x % y == 0)
        {
            cnt++;
        }
    }

    if (cnt == 2)
    {
        cout << "This number is a PRIME number!" << endl;
    }
    else
    {
        cout << "This number is NOT a prime number!" << endl;
    }

    return 0;
}