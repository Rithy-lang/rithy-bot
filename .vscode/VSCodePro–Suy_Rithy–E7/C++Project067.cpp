#include <iostream>

using namespace std;

int main()
{
    char str1[100], str2[200], x = 0, y = 0, flag = 0;
    cout << "Comparing two Strings using for loop \n"
         << endl;

    cout << "Insert first string: " << endl;
    cin >> str1;

    cout << "Insert second string: " << endl;
    cin >> str2;

    while (str1[x] != '\0')
    {
        x++;
    }

    while (str2[y] != '\0')
    {
        y++;
    }

    if (x != y)
    {
        flag = 0;
    }
    else
    {
        for (x = 0, y = 0; str1[x] != '\0', str2[y] != '\0'; x++, y++)
        {
            if (str1[x] == str2[y])
            {
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Strings are NOT equal!" << endl;
    }
    else
    {
        cout << "Strings are EQUAL!" << endl;
    }

    return 0;
}