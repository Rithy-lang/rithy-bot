#include <iostream>

using namespace std;

int call_value(int a, int b);

int main()
{
    int x, y, sum;
    cout << "Call by Value \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << " Insert second number: " << endl;
    cin >> y;

    sum = call_value(x, y);

    cout << "The sum of " << x << " and " << y << " is: " << sum << endl;

    return 0;
}

int call_value(int a, int b)
{
    int sum;
    sum = a + b;

    return sum;
}