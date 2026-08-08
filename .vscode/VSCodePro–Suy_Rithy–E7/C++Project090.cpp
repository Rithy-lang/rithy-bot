#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    char data[500], ch;
    cout << "Static Storage Class \n"
         << endl;

    ofstream fout("C:/Users/USER/Desktop/CFiles/C++.txt", ios::out);

    cout << "Insert some text into the file: " << endl;
    for (int x = 0; x < 4; x++)
    {
        cin.get(data, 500);
        cin.get(ch);
        fout << data << endl;
    }

    fout.close();

    return 0;
}