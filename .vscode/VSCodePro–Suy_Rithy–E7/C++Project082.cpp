#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n, s, amt[200];
    cout << "Search for Element in an Array \n"
         << endl;

    cout << "Insert range of array elements: " << endl;
    cin >> n;

    cout << "Insert elements of array: " << endl;
    for (int a = 0; a < n; a++)
    {
        cin >> amt[a];
    }

    cout << "Choose an element to find within the array: " << endl;
    cin >> s;

    x = 0;
    y = n - 1;
    z = (x + y) / 2;

    while (x <= y)
    {
        if (amt[z] == s)
        {
            cout << s << " found at location " << z + 1 << endl;
            break;
        }
        else if (amt[z] < s)
        {
            x = z + 1;
        }
        else
        {
            y = z + 1;
            z = (x + y) / 2;
        }
    }

    if (x > y)
    {
        cout << s << " is not found in the array list!" << endl;
    }

    return 0;
}