#include <iostream>

using namespace std;

int main()
{
    int amt[200], mini, len, pos = 1;
    cout << "Minimum Element in Array \n"
         << endl;

    cout << "Choose the range of array element: " << endl;
    cin >> len;

    cout << "Insert " << len << " array elements only: " << endl;
    for (int x = 0; x < len; x++)
    {
        cin >> amt[x];
    }

    mini = amt[0];

    for (int x = 1; x < len; x++)
    {
        if (amt[x] < mini)
        {
            mini = amt[x];
            pos = x + 1;
        }
    }

    cout << "The minimum element is at position " << pos << " and its value is " << mini << endl;

    return 0;
}