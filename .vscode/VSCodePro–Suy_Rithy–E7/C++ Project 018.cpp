#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cout << "Nested for loop \n"
         << endl;

    for (x = 2; x <= 100; x++)
    {
        for (y = 2; y <= (x / y); y++)
            if (!(x % y))
            {
                break;
            }
        if (y > (x / y))
        {
            cout << x << " is a prime number" << endl;
        }
    }

    return 0;
}