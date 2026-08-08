#include <iostream>

using namespace std;

int main()
{
    int yr;
    cout << "A program to detect a leap year \n"
         << endl;

    cout << "Insert any year of your choice: " << endl;
    cin >> yr;

    if (yr % 4 == 0)
    {
        cout << yr << " is a LEAP year!" << endl;
    }
    else
    {
        cout << yr << " is NOT a leap year!" << endl;
    }

    return 0;
}