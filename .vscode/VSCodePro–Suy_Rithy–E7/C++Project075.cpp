#include <iostream>

using namespace std;

void case_lower(char str[]);

int main()
{
    char str[200];
    cout << "Uppercase to Lowercase using a while loop \n"
         << endl;

    cout << "Insert uppercase strings to convert to lowercase: " << endl;
    cin >> str;

    case_lower(str);

    cout << "The result of the lowercase conversion is: " << str << endl;

    return 0;
}

void case_lower(char str[])
{
    int x = 0;
    while (str[x] != '\0')
    {
        if (str[x] >= 'A' && str[x] <= 'Z')
        {
            str[x] = str[x] + 32;
        }
        x++;
    }
}