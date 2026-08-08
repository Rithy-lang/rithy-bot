#include <iostream>

using namespace std;

int main()
{
    char str1[100], str2[100];
    int x, y;
    cout << "Concatenation using a for loop \n"
         << endl;

    cout << "Insert first string: " << endl;
    cin >> str1;

    cout << "Insert second string: " << endl;
    cin >> str2;

    for (x = 0; str1[x] != '\0'; ++x)
        ;

    for (y = 0; str2[y] != '\0'; ++y, ++x)
    {
        str1[x] = str2[y];
    }

    str1[x] = '\0';

    cout << "String concatenated successfully..." << str1 << endl;

    return 0;
}