#include <iostream>

using namespace std;

int main()
{
    int rem, x;
    long y = 0, z = 0, temp;
    cout << "Generate Armstrong Numbers \n"
         << endl;

    cout << "Insert range of Armstrong numbers: " << endl;
    cin >> y;

    cout << "The list of Armstrong numbers up to " << y << " are " << endl;
    for (x = 1; x <= y; x++)
    {
        temp = x;
        while (temp != 0)
        {
            rem = temp % 10;
            z = z + rem * rem * rem;
            temp = temp / 10;
        }
        if (x == z)
        {
            cout << x << endl;
        }
        z = 0;
    }

    return 0;
}