#include <iostream>

using namespace std;

void case_upper(char str[]);

int main()
{
    char str[200];
    cout << "Lowercase to Uppercase using while loop \n"
         << endl;

    cout << "Insert lowercase string to convert to uppercase: " << endl;
    cin >> str;

    case_upper(str);

    cout << "The conversion of lowercase to uppercase is: " << str << endl;

    return 0;
}

void case_upper(char str[])
{
    int x = 0;

    while (str[x] != '\0')
    {
        if (str[x] >= 'a' && str[x] <= 'z')
        {
            str[x] = str[x] - 32;
        }
        x++;
    }
}