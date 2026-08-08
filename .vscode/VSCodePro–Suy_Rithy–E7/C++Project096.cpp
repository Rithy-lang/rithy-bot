#include <iostream>

using namespace std;

inline int additon(int a, int b)
{
    int c = a - b;
    return (c);
}

int main()
{
    cout << "Inline Function \n"
         << endl;

    cout << "The addition of numbers is " << additon(13, 8) << endl;

    cout << "The addition of numbers is " << additon(67, 5) << endl;

    return 0;
}