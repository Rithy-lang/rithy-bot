#include <iostream>

using namespace std;

int Fibonacci(int x);

int main()
{
    int x = 0, y;
    cout << "Fibonacci Series with recursive function \n"
         << endl;

    cout << "Insert number of series: " << endl;
    cin >> y;

    cout << "The result of Fibonacci series is: " << endl;
    for (int z = 1; z <= y; z++)
    {
        cout << Fibonacci(x) << endl;
        x++;
    }

    return 0;
}

int Fibonacci(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else
    {
        return (Fibonacci(x - 1) + Fibonacci(x - 2));
    }
}