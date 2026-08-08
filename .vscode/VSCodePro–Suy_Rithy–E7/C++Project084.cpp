#include <iostream>

using namespace std;

void sort_bubble(int amt[], int n);

int main()
{
    int amt[200], n, x, sw;
    cout << "Sorting of Array elements using Bubble method \n"
         << endl;

    cout << "Insert range of array elements: " << endl;
    cin >> n;

    cout << "Insert elements of the array: " << endl;
    for (x = 0; x < n; x++)
    {
        cin >> amt[x];
    }

    sort_bubble(amt, n);

    cout << "The sorted array is: " << endl;
    for (x = 0; x < n; x++)
    {
        cout << amt[x] << endl;
    }

    return 0;
}

void sort_bubble(int amt[], int n)
{
    int x;
    for (int y = 0; y < (n - 1); y++)
    {
        for (int z = 0; z < n - y - 1; z++)
        {
            if (amt[z] > amt[z + 1])
            {
                x = amt[z];
                amt[z] = amt[z + 1];
                amt[z + 1] = x;
            }
        }
    }
}