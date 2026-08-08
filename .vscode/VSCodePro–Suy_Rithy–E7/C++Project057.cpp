#include <iostream>

using namespace std;

int main()
{
    int amt[200], pos, x, y, num;
    cout << "Insert Element in an Array \n"
         << endl;

    cout << "Choose range of array elements: " << endl;
    cin >> x;

    cout << "Insert " << x << " array elements only" << endl;
    for (y = 0; y < x; y++)
    {
        cin >> amt[y];
    }

    cout << "Choose a position to insert new element: " << endl;
    cin >> pos;

    cout << "Insert the new element: " << endl;
    cin >> num;

    for (y = x - 1; y >= pos - 1; y--)
    {
        amt[y + 1] = amt[y];
    }

    amt[pos - 1] = num;

    cout << "The new array element after insertion is: " << endl;
    for (y = 0; y <= x; y++)
    {
        cout << amt[y] << endl;
    }
    return 0;
}