#include <iostream>

using namespace std;

int main()
{
    char STR1[200];
    cout << "String Input \n"
         << endl;

    cout << "Insert some strings: " << endl;

    cin.getline(STR1, 200);

    cout << "You entered: " << STR1 << endl;

    return 0;
}