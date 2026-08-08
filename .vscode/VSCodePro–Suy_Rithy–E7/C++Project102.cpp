#include <iostream>

using namespace std;

int main()
{
    char ch, data = 'A';
    cout << "Alphabet Right Angle Triangle \n"
         << endl;

    cout << "Insert an uppercase character of the last alphabet: " << endl;
    cin >> ch;

    for (int x = 1; x <= (ch - 'A' + 1); ++x)
    {
        for (int y = 1; y <= x; ++y)
        {
            cout << data << " ";
        }
        ++data;

        cout << endl;
    }

    return 0;
}