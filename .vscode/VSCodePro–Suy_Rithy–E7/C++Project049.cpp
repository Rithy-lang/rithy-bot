#include <iostream>

using namespace std;

int main()
{
    long x, dec, y, ba = 1, oct = 0;
    cout << "Decimal to Octal \n"
         << endl;

    cout << "Insert a Decimal Number: " << endl;
    cin >> x;

    dec = x;

    while (x > 0)
    {
        y = x % 8;
        oct = oct + y * ba;
        x = x / 8;
        ba = ba * 10;
    }

    cout << "The Octal equivalent of " << dec << " is " << oct << endl;

    return 0;
}