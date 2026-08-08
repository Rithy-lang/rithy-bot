#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    cout << "Reverse a string using Strrev Function \n"
         << endl;

    cout << "Insert a string: " << endl;
    cin >> str;

    strrev(str);

    cout << "The reversed string is : " << str << endl;

    return 0;
}