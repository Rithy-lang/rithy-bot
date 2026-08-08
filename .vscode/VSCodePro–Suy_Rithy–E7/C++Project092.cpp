#include <iostream>

using namespace std;

int addition(int x, int y);

int main()
{
    int x, y, sum;
    cout << "Add two numbers using function \n"
         << endl;

    cout << "Insert first numbers: " << endl;
    cin >> x;

    cout << "Insert second numbers: " << endl;
    cin >> y;

    sum = addition(x, y);

    cout << "The addition of " << x << " and " << y << " is " << sum << endl;

    return 0;
}

int addition(int x, int y)
{
    int sum;
    sum = x + y;
    return sum;
}