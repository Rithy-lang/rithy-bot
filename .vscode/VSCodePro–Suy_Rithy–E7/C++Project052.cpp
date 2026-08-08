#include <iostream>

using namespace std;

int main()
{
    int x, n, Arr[100];
    cout << "Detect first and last values in an Array \n"
         << endl;

    cout << "Choose range of Array element: " << endl;
    cin >> n;

    cout << "Insert only " << n << " numbers" << endl;
    for (x = 0; x < n; ++x)
    {
        cin >> Arr[x];
    }

    cout << "The first number is " << Arr[0] << " and " << " the last number is " << Arr[n - 1];

    return 0;
}