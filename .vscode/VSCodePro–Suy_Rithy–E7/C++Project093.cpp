#include <iostream>

using namespace std;

int subtraction(int x, int y);

int main()
{
    int x, y, sub;
    cout << "Subtraction of two numbers using a function \n"
         << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    sub = subtraction(x, y);

    cout << "The result of subtraction of " << x << " and " << y << " is " << sub << endl;

    return 0;
}

int subtraction(int x, int y)
{
    int sub;
    sub = x - y;
    return sub;
}