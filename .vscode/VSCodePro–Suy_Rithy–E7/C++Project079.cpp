#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[200], ch;
    int x, cnt = 0;
    cout << "Character Frequency in a sentence \n"
         << endl;

    cout << "Insert some string: " << endl;
    cin.getline(str, 1000);

    cout << "Choose a character to find its number of occurances: " << endl;
    cin >> ch;

    for (x = 0; str[x] != '\0'; ++x)
    {
        if (ch == str[x])
            ++cnt;
    }

    cout << "The frequency of character occurance is: " << cnt << endl;

    return 0;
}