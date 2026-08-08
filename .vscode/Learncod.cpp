#include <iostream>
using namespace std;

int main()
{
    string name, gender;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your gender (M/F): ";
    cin >> gender;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18)
    {
        cout << age << "! You are eligible to vote." << endl;
    }
    else
    {
        cout << age << "! You are not eligible to vote." << endl;
    }
    return 0;
}
