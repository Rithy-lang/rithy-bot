#include <iostream>

using namespace std;

int len_str(char *);

int main()
{
    char str[100];
    int len;
    cout << "Length of string using pointer \n"
         << endl;

    cout << "Insert any string to calculate its length: " << endl;
    cin >> str;

    len = len_str(str);

    cout << "The length of the string is: " << len << endl;

    return 0;
}

int len_str(char *ptr)
{
    int cnt = 0;
    while (*ptr != '\0')
    {
        cnt++;
        ptr++;
    }
    return cnt;
}