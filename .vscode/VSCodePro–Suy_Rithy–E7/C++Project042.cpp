#include <iostream>

using namespace std;

int main()
{
    int x, y, z = 0, n = 1;
    cout << "Fibonacci Series \n"
         << endl;

    cout << "Choose number of terms in series: " << endl;
    cin >> x;

    cout << "The result of the Fibonacci series is : " << endl;

    for (int a = 0; z < x; a++)
    {
        if (a <= 1)
        {
            y = a;
        }
        else
        {
            y = z + n;
            z = n;
            n = y;
        }
        cout << y << endl;
    }

    return 0;
}