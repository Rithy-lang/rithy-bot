#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100], rev;
    int x, y = 0;
    cout << "Reverse a string using while loop \n"
         << endl;

    cout << "Insert a string: " << endl;
    cin >> str;

    x = 0;
    y = strlen(str) - 1;

    while (x < y)
    {
        rev = str[x];
        str[x] = str[y];
        str[y] = rev;
        x++;
        y--;
    }

    cout << "The reversed string  = " << str << endl;

    return 0;
}