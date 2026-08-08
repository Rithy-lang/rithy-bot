#include <iostream>

using namespace std;

int main()
{
    int amt[200], maxi, len, pos = 1;

    cout << "Maximum Element in an Array \n"
         << endl;

    cout << "Choose range of array elements: " << endl;
    cin >> len;

    cout << " Insert " << len << " Elements of the array only" << endl;
    for (int x = 0; x < len; x++)
    {
        cin >> amt[x];
    }

    maxi = amt[0];

    for (int x = 1; x < len; x++)
    {
        if (amt[x] > maxi)
        {
            maxi = amt[x];
            pos = x + 1;
        }
    }

    cout << "The maximum element is at position " << pos << " and it's value is " << maxi << endl;

    return 0;
}