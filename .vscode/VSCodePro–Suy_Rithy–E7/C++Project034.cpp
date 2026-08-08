#include <iostream>

using namespace std;

int main()
{
    int x, y, rev[100];
    cout << "Reverse of Array of Numbers \n"
         << endl;

    cout << "Insert range of number: " << endl;
    cin >> x;

    cout << "Insert only " << x << " numbers: " << endl;
    for (y = 0; y < x; y++)
    {
        cin >> rev[y];
    }

    cout << "The reversed numbers are: \n"
         << endl;
    for (y = x - 1; y >= 0; y--)
    {
        cout << rev[y] << endl;
    }
    return 0;
}