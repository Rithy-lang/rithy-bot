#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[100], str2[100];
    cout << "Copy Strings using Strcpy function \n"
         << endl;

    cout << "Insert some strings: " << endl;
    cin >> str1;

    strcpy(str2, str1);

    cout << "String coped successfully..." << str2 << endl;

    return 0;
}