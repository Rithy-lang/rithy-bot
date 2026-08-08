#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[200], str2[100];
    cout << "Compare Strings using Strcmp() function \n"
         << endl;

    cout << "Insert first string: " << endl;
    cin >> str1;

    cout << "Insert second string: " << endl;
    cin >> str2;

    if (strcmp(str1, str2) == 0)
    {
        cout << "The strings are EQUAL" << endl;
    }
    else
    {
        cout << "The strings are NOT equal" << endl;
    }

    return 0;
}