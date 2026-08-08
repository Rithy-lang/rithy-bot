#include <iostream>

using namespace std;

int main()
{
    int grade;
    cout << "else if statement \n"
         << endl;

    cout << "Insert student's mark: " << endl;
    cin >> grade;

    if (grade > 100)
    {
        cout << "Incorrect grade" << endl;
    }
    else if (grade >= 80)
    {
        cout << "Your grade is A" << endl;
    }
    else if (grade >= 70)
    {
        cout << "Your grade is B" << endl;
    }
    else if (grade >= 50)
    {
        cout << "Your grade is C" << endl;
    }
    else if (grade >= 45)
    {
        cout << "Your grade is D" << endl;
    }
    else if (grade >= 35)
    {
        cout << "Your grade is D" << endl;
    }
    else
    {
        cout << "You FAILED" << endl;
    }

    return 0;
}