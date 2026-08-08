#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[100], str2[100];
    cout << "String concatenation using Strcat Function \n"
         << endl;

    cout << "Insert first string: " << endl;
    cin >> str1;

    cout << "Insert second string: " << endl;
    cin >> str2;

    strcat(str1, str2);

    cout << "String concatenated successfully..." << str1 << endl;

    return 0;
}