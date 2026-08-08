#include <iostream>

using namespace std;

int main()
{
    int x, y, sum = 0;
    cout << "Add a given digit \n"
         << endl;

    cout << "Insert some numbers: " << endl;
    cin >> x;

    do
    {

        y = x % 10;

        sum = sum + y;

        x = x / 10;

    } while (x != 0);

    cout << "The result of the added numbers = " << sum << endl;

    return 0;
}