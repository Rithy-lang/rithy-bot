#include <iostream>

using namespace std;

int main()
{
    long int bin, hex = 0, x = 1, y, z;
    cout << "Binary to Hexadecimal \n"
         << endl;

    cout << "Insert binary numbers only: " << endl;
    cin >> bin;

    z = bin;

    while (bin != 0)
    {
        y = bin % 10;
        hex = hex + y * x;
        x = x * 2;
        bin = bin / 10;
    }

    cout << "The Hexadecimal equivalent of " << z << " is " << hex << endl;

    return 0;
}