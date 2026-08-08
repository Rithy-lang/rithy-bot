#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y, maxi, ran;
    cout << "Random Number Generator \n"
         << endl;

    cout << "Choose range of random numbers to generate: " << endl;
    cin >> x;

    cout << "Choose maximum value of random numbers: " << endl;
    cin >> maxi;

    cout << "The result of the random numbers are: " << endl;

    for (y = 0; y <= x; y++)
    {
        ran = rand() % maxi;
        cout << ran << endl;
    }

    return 0;
}