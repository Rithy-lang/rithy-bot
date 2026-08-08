#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    cout << "do while loop \n"
         << endl;

    do
    {

        cout << "The value of x = " << x << endl;
        x = x + 1;

    } while (x <= 20);

    return 0;
}