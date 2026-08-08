#include <iostream>

using namespace std;

int main()
{
    int x, y, sum;
    cout << "Addition of two numbers \n"
         << endl;

    cout << "Insert first number: " << endl;

    cin >> x;

    cout << "Insert second number: " << endl;

    cin >> y;

    sum = x + y;

    cout << "The result of x + y = " << sum << endl;

    return 0;
}