#include <iostream>

using namespace std;

int main()
{
    int principal_amount;
    float rate, period, simple_interest;

    cout << "Simple Interest \n"
         << endl;

    cout << "Insert Principal Amount: " << endl;
    cin >> principal_amount;

    cout << "Insert Rate: " << endl;
    cin >> rate;

    cout << "Insert the period: " << endl;
    cin >> period;

    simple_interest = (principal_amount * rate * period) / 100;

    cout << "\n The result of the simple interest = " << simple_interest << endl;

    return 0;
}