#include <iostream>

using namespace std;

int main()
{
    int x, y;
    x = 80;
    y = 52;
    cout << "Nested if Statement \n"
         << endl;

    if (x == 80)
    {
        cout << "The first condition is met" << endl;
        if (y == 52)
        {
            cout << "This is a NESTED if statement" << endl;
        }
    }

    return 0;
}