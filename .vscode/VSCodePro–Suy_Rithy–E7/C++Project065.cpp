#include <iostream>

using namespace std;

int main()
{
    int x, cnt = 0;
    char STR[20];
    cout << "String Length with for loop \n"
         << endl;

    cout << "Insert strings of any character: " << endl;
    cin >> STR;

    for (x = 0; STR[x] != '\0'; x++)
    {

        cnt++;
    }

    cout << "The length of the given string is: " << cnt << endl;

    return 0;
}