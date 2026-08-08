#include <iostream>

using namespace std;

int main()
{
    int x = 87, y = 70;
    cout << "Nested Switch case \n"
         << endl;

    switch (x)
    {
    case 87:
        cout << "This is the first switch case" << endl;

        switch (y)
        {
        case 70:
            cout << "This is the second switch case" << endl;
        }
    }
    return 0;
}