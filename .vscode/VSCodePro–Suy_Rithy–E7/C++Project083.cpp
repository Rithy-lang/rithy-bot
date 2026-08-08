#include <iostream>

using namespace std;

int arr_search(int amt[], int x, int y, int a, int b);

int main()
{
    int amt[50], x, y, z, output, a, b;
    cout << "Search element of an Array using Recursive \n"
         << endl;

    cout << "Insert range of array elements: " << endl;
    cin >> x;

    cout << "Insert elements of the array: " << endl;
    for (y = 0; y < x; y++)
    {
        cin >> amt[y];
    }

    cout << "Insert the element to search within the array: " << endl;
    cin >> z;

    a = 0, b = x - 1;

    output = arr_search(amt, x, z, a, b);

    if (output == 0)
    {
        cout << "The Number is found " << endl;
    }
    else
    {
        cout << "The Number is not found. " << endl;
    }

    return 0;
}

int arr_search(int amt[], int x, int y, int a, int b)
{
    int z, output = 0;
    if (a <= b)
    {
        z = (a + b) / 2;
        if (y == amt[z])
        {
            output = 1;
        }
        else if (y < amt[z])
        {
            return arr_search(amt, x, y, a, z - 1);
        }
        else
        {
            return arr_search(amt, x, y, z + 1, b);
        }
    }
    else
    {
        return output;
    }
}