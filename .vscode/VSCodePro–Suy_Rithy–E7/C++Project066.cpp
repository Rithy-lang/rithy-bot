#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char STR[100];
    int len;
    cout << "Find String length using function \n"
         << endl;

    cout << "Insert string of any length: " << endl;
    cin >> STR;

    len = strlen(STR);

    cout << "The length of the string is : " << len << endl;

    return 0;
}