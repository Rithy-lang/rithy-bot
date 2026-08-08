#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    char data[500], ch;

    cout << "File Handling..." << endl;

    ifstream fin("C:/Users/USER/Desktop/CFiles/C++.txt", ios::in);
    fin.seekg(0);

    cout << "\n"
         << endl;
    for (int x = 0; x < 5; x++)
    {
        fin.get(data, 500);
        fin.get(ch);
        cout << data << "\n"
             << endl;
    }

    fin.close();

    return 0;
}