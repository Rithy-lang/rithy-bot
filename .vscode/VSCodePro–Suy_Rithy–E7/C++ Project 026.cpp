#include <iostream>

using namespace std;

int main()
{
    int basic, x, y, gro_sa;

    cout << "Gross Salary \n"
         << endl;

    cout << "Insert your basic salary: " << endl;
    cin >> basic;

    x = (10 * basic) / 100;
    y = (12 * basic) / 100;

    gro_sa = basic + x + y;

    cout << "Your Gross salary = " << gro_sa << endl;

    return 0;
}