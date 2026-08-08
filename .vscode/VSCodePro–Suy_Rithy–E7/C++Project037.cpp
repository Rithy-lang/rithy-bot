#include <iostream>

using namespace std;

int list_prime(int n);

int main()
{
    int x, y, z;
    cout << "List of Prime numbers up to a given number \n"
         << endl;

    cout << "Choose the range of prime numbers: ";
    cin >> x;

    for (y = 2; y <= x; y++) // ចាប់ផ្តើមពី 2 (ព្រោះ 0 និង 1 មិនមែនជា Prime Number)
    {
        z = list_prime(y);

        if (z == 1)
        {
            cout << y << endl;
        }
    }

    return 0;
}

int list_prime(int n)
{
    if (n < 2)
        return 0; // លេខតូចជាង 2 មិនមែនជា Prime Number ទេ

    for (int x = 2; x <= n - 1; x++)
    {
        if (n % x == 0)
            return 0; // បើចែកដាច់ មិនមែនជា Prime Number ទេ
    }

    return 1; // បើគ្មានលេខណាDivideដាច់ទេ វាជា Prime Number
}