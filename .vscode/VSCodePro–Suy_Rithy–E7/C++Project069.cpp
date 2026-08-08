#include <iostream>

using namespace std;

int main()
{
    char str1[100], str2[100], x;
    cout << "Copy strings using for loop \n"
         << endl;

    cout << "Insert a string: " << endl;
    cin >> str1;

    for (x = 0; str1[x] != '\0'; ++x)
    {
        str2[x] = str1[x];
    }

    str2[x] = '\0';

    cout << "String copied successfully... " << str2 << endl;

    return 0;
}