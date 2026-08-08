#include <iostream>

using namespace std;

void show(char = 'A', int = 20);

int main()
{
    cout << "Passing Default Argument to a function \n"
         << endl;

    cout << "Argument is not passed here:" << endl;
    show();

    cout << "Argument is passed here:" << endl;
    show('B');

    cout << "Argument is not passed here:" << endl;
    show('B', 10);

    return 0;
}

void show(char ch, int x)
{
    for (int y = 1; y <= x; ++y)
    {
        cout << ch << endl;
    }
    cout << endl;
}