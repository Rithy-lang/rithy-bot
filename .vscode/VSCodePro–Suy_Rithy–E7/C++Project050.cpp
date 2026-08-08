#include <iostream>

using namespace std;

int main()
{
    long x, dec, y, ba = 1, bin = 0;
    cout << "Decimal to Binary \n"
         << endl;

    cout << "Insert Decimal Number: " << endl;
    cin >> x;

    dec = x;

    while (x > 0)
    {
        y = x % 2;
        bin = bin + y * ba;
        x = x / 2;
        ba = ba * 10;
    }

    cout << "The Binary equivalent of " << dec << " is " << bin << endl;

    return 0;
}