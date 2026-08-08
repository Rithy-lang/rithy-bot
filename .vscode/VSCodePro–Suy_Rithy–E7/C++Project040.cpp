#include <iostream>

using namespace std;

int main()
{
    int x, fact = 1;
    cout << "Factorial \n"
         << endl;

    cout << "Insert any number to find the factorial: " << endl;
    cin >> x;

    for (int y = 1; y <= x; y++)
    {
        fact = fact * y;
    }

    cout << "The factorial of the given number = " << fact << endl;

    return 0;
}