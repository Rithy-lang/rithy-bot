#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[200];
    cout << "Uppercase to Lowercase using strupr function \n"
         << endl;

    cout << "Insert Uppercase string for conversion: " << endl;
    cin >> str;

    strupr(str);

    cout << "The result of conversion to uppercase is: " << str << endl;

    return 0;
}