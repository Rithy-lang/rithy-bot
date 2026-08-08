#include <iostream>

using namespace std;

int main()
{
    int bin, dec = 0, x = 1, y, z;
    cout << "Binary to Decimal \n"
         << endl;

    cout << "Insert binary numbers only: " << endl;
    cin >> bin;

    z = bin;

    while (bin > 0)
    {
        y = bin % 10;
        dec = dec + y * x;
        bin = bin / 10;
        bin = bin / 10;
        x = x * 2;
    }

    cout << "The Decimal equivalent of " << z << " is " << dec << endl;

    return 0;
}