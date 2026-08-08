#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cout << "Find greatest of three numbers with if statement \n"
         << endl;

    cout << "Insert first number: \n"
         << endl;
    cin >> x;

    cout << "Insert second number: \n"
         << endl;
    cin >> y;

    cout << "Insert third number: \n"
         << endl;
    cin >> z;

    if (x >= y && x >= z)
    {
        cout << "\n"
             << x << " is the greatest number \n"
             << endl;
    }

    if (y >= x && y >= z)
    {
        cout << y << " is the greatest number \n"
             << endl;
    }

    if (z >= x && z >= y)
    {
        cout << z << " is the greatest number \n"
             << endl;
    }
    return 0;
}