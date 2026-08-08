#include <iostream>

using namespace std;

int main()
{
    int x, y, row, col, mat[100][100], trans[100][100];
    cout << "Transpose Matrix \n"
         << endl;

    cout << "Insert numbers of rows: " << endl;
    cin >> x;

    cout << "Insert numbers of column: " << endl;
    cin >> y;

    cout << "Insert elements of the matrix : " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            cin >> mat[row][col];
        }
    }

    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            trans[row][col] = mat[row][col];
        }
    }

    cout << "The result of the transpose is: " << endl;
    for (row = 0; row < y; row++)
    {
        for (col = 0; col < x; col++)
        {
            cout << trans[row][col] << endl;
        }
        cout << "\n"
             << endl;
    }

    return 0;
}