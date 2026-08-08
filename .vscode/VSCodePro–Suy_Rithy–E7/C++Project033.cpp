#include <iostream>

using namespace std;

int main()
{
    int x, rev = 0, y;
    cout << "How to Reverse Numbers \n"
         << endl;

    cout << "Insert some numbers: " << endl;
    cin >> x;

    while (x != 0)
    {
        y = x % 10;
        rev = rev * 10 + y;
        x = x / 10;
    }

    cout << "The reversed of numbers = " << rev << endl;

    return 0;
}