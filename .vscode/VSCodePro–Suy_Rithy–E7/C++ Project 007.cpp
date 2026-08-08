#include <iostream>

using namespace std;

int main()
{
    int x, y, sum, mul, sub, mod;
    float div;
    cout << "Addition, Subtraction, Multiplication and Division of two numbers" << endl;

    cout << "Insert first number: " << endl;
    cin >> x;

    cout << "Insert second number: " << endl;
    cin >> y;

    sum = x + y;
    mul = x * y;
    sub = x - y;
    mod = x % y;
    div = x / y;

    cout << "The sum of " << x << " + " << y << " = " << sum << endl;
    cout << "The Multiplication of x * y = " << mul << endl;
    cout << "The subtraction of x - y = " << sub << endl;
    cout << "The modulus of x%y = " << mod << endl;
    cout << "The division of x/y = " << div << endl;

    return 0;
}