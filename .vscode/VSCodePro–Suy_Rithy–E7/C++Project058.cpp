#include <iostream>

using namespace std;

int main()
{
    int x, y, amt[200], pos;
    cout << "Delete an Element from Array \n " << endl;

    cout << "Choose range of array element" << endl;
    cin >> x;

    cout << "Insert " << x << " array elements only" << endl;
    for (y = 0; y < x; y++)
    {
        cin >> amt[y];
    }

    cout << "Choose the position of the element you want to delete: " << endl;
    cin >> pos;

    if (pos >= x + 1)
    {
        cout << "The operation is not possible..." << endl;
    }
    else
    {
        for (y = pos - 1; y < x - 1; y++)
        {
            amt[y] = amt[y + 1];
        }
    }

    cout << "The result of the array after deletion is: " << endl;
    for (y = 0; y < x - 1; y++)
    {
        cout << amt[y] << endl;
    }

    return 0;
}