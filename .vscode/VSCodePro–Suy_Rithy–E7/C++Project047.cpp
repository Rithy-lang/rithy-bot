#include <iostream>

using namespace std;

int main()
{
    long int bin, oct = 0, x = 1, y, z;
    cout << "Binary to Octal \n"
         << endl;

    cout << "Insert binary numbers only: " << endl;
    cin >> bin;

    z = bin;

    while (bin != 0)
    {
        y = bin % 10;
        oct = oct + y * x;
        x = x * 2;
        bin = bin / 10;
    }

    cout << "The Octal equivalent of " << z << " is " << oct << endl;

    return 0;
}