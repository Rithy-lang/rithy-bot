#include <iostream>

using namespace std;

int main()
{
    int n, amt[200], x, y, z;
    cout << "Sorting Array elements using Insertion \n"
         << endl;

    cout << "Choose range of array elements: " << endl;
    cin >> n;

    cout << "Insert elements of the array: " << endl;
    for (x = 0; x < n; x++)
    {
        cin >> amt[x];
    }

    for (x = 1; x <= n - 1; x++)
    {
        y = x;

        while (y > 0 && amt[y] < amt[y - 1])
        {
            z = amt[y];
            amt[y] = amt[y - 1];
            amt[y - 1] = z;
            y--;
        }
    }

    cout << "The sorted array is: " << endl;
    for (x = 0; x <= n - 1; x++)
    {
        cout << amt[x] << endl;
    }

    return 0;
}