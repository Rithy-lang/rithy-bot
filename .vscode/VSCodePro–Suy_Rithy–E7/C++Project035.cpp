#include <iostream>

using namespace std;

int main()
{
    int x, y, pal, rev = 0;
    cout << "Checking a Palindrome \n"
         << endl;

    cout << "Insert only positive numbers: " << endl;
    cin >> x;

    y = x;

    while (x != 0)
    {
        pal = x % 10;

        rev = (rev * 10) + pal;

        x = x / 10;
    }

    if (y == rev)
    {
        cout << "This number is a PALINDROME!" << endl;
    }
    else
    {
        cout << "This number is NOT a palindrome" << endl;
    }

    return 0;
}