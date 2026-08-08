#include <iostream>

using namespace std;

long HCFLCM(long x, long y);

int main()
{
    long x, y, HCF, LCM;
    cout << "Calculate LCM and HCF \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    HCF = HCFLCM(x, y);

    LCM = (x * y) / HCF;

    cout << "The HCF of " << x << " and " << y << " is " << HCF << endl;

    cout << "\n The LCM of " << x << " and " << y << " is " << LCM << endl;

    return 0;
}

long HCFLCM(long x, long y)
{
    if (x == 0)
    {
        return y;
    }
    do
    {
        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        }
    } while (y != 0);

    return x;
}