#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Even/Odd numbers \n"
         << endl;

    cout << "Insert any number: " << endl;
    cin >> x;

    if (x % 2 == 0)
    {
        cout << x << " is an EVEN number" << endl;
    }
    else
    {
        cout << x << " is an ODD number" << endl;
    }

    return 0;
}