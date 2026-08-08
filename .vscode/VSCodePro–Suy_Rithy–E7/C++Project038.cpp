#include <iostream>

using namespace std;

int main()
{
    int x, y, z = 0, temp, rem;
    cout << "Armstrong Numbers \n"
         << endl;

    cout << "Insert any number to check for Armstrong: " << endl;
    cin >> x;

    temp = x;

    while (temp != 0)
    {
        rem = temp % 10;
        z = z + rem * rem * rem;
        temp = temp / 10;
    }

    if (x == z)
    {
        cout << "This number is an ARMSTRONG number!" << endl;
    }
    else
    {
        cout << "This number is NOT an Armstrong number!" << endl;
    }

    return 0;
}