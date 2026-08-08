#include <iostream>

using namespace std;

int fact(int n);

int main()
{
    int x;
    cout << "Factorial with Recursive function \n"
         << endl;

    cout << "Insert any number to find the factorial: " << endl;
    cin >> x;

    cout << "The result of the factorial is " << fact(x) << endl;

    return 0;
}

int fact(int n)
{
    if (n > 1)
    {
        return n * fact(n - 1);
    }
    else
    {
        return 1;
    }
}