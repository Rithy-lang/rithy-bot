#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Check for Vowel and Consonant \n"
         << endl;

    cout << "Insert a character: " << endl;
    cin >> ch;

    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
    {
        cout << "The character " << ch << " is a VOWEL!" << endl;
    }
    else
    {
        cout << "The character " << ch << " is a CONSONANT!" << endl;
    }

    return 0;
}