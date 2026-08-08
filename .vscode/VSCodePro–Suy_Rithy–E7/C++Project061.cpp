#include <iostream>

using namespace std;

int main()
{
    int x, y, row, col, mat1[200][200], mat2[200][200], sub[200][200];
    cout << "Subtraction of Matrices \n"
         << endl;

    cout << "Insert the number of rows: " << endl;
    cin >> x;

    cout << "Insert the number of column: " << endl;
    cin >> y;

    cout << "Insert elements of first array: " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            cin >> mat1[row][col];
        }
    }

    cout << "Insert elements of second array: " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            cin >> mat2[row][col];
        }
    }

    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            sub[row][col] = mat1[row][col] - mat2[row][col];
        }
    }

    cout << "The result of the subtraction of the two matrices is: " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            cout << sub[row][col] << endl;
        }
        cout << "\n"
             << endl;
    }

    return 0;
}