#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    cout << "Uppercase to Lowercase using strlwr function \n"
         << endl;

    cout << "Insert Uppercase string to convert to lowercase: " << endl;
    cin >> str;

    strlwr(str);

    cout << "The result of the string conversion is: " << str << endl;

    return 0;
}