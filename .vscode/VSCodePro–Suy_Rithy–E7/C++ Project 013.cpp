#include <iostream>

using namespace std;

int main()
{
    char grade;
    cout << "Switch Statement \n"
         << endl;

    cout << "Please insert your grade from A-F only" << endl;
    std::cin >> grade;

    switch (grade)
    {
    case 'A':
        cout << "Excellent Result" << endl;
        break;

    case 'B':
        cout << "Very Good Result" << endl;
        break;

    case 'C':
        cout << "Good Result" << endl;
        break;

    case 'D':
        cout << "Well done Result" << endl;
        break;

    case 'E':
        cout << "Passed Result" << endl;
        break;

    case 'F':
        cout << "Failed Result" << endl;
        break;

    default:
        cout << "Invalid grade" << endl;
    }

    return 0;
}