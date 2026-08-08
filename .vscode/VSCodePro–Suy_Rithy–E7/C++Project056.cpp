#include <iostream>

using namespace std;

int main()
{
    int x, y, z, amt1[200], amt2[200];
    cout << "Reverse Array Elements \n"
         << endl;

    cout << "Choose range of elements: " << endl;
    cin >> x;

    cout << "Insert " << x << "array elements only: " << endl;
    for (y = 0; y < x; y++)
    {
        cin >> amt1[y];
    }

    for (y = y - 1, z = 0; y >= 0; y--, z++)
    {
        amt2[z] = amt1[y];
    }

    for (y = 0; y < x; y++)
    {
        amt1[y] = amt2[y];
    }

    cout << "The reversed array element is: " << endl;
    for (y = 0; y < x; y++)
    {
        cout << amt1[y] << endl;
    }

    return 0;
}