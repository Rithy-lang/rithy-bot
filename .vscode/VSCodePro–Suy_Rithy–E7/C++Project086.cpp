#include <iostream>

using namespace std;

int main()
{
    int amt[200], n, x, y, pos, z;
    cout << "Sorting array elements using selection \n"
         << endl;

    cout << "Insert range of array element: " << endl;
    cin >> n;

    cout << "Insert the elements of the array: " << endl;
    for (x = 0; x < n; x++)
    {
        cin >> amt[x];
    }

    for (x = 0; x < (n - 1); x++)
    {
        pos = x;
        for (y = x + 1; y < n; y++)
        {
            if (amt[pos] > amt[y])
            {
                pos = y;
            }
        }

        if (pos != x)
        {
            z = amt[x];
            amt[x] = amt[pos];
            amt[pos] = z;
        }
    }

    cout << "The result of the sorted array is: " << endl;
    for (x = 0; x < n; x++)
    {
        cout << amt[x] << endl;
    }

    return 0;
}