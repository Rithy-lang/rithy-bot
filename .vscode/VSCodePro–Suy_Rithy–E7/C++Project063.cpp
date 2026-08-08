#include <iostream>

using namespace std;

int main()
{
    int x, y, row, col, a, b, z, sum = 0, mat1[20][20], mat2[20][20], mul[20][20];
    cout << "Multiplication of two Matrices \n"
         << endl;

    cout << "Insert number of rows of first matrix: " << endl;
    cin >> x;

    cout << "Insert number of column of first matrix: " << endl;
    cin >> y;

    cout << "Insert elements of the first matrix: " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < y; col++)
        {
            cin >> mat1[row][col];
        }
    }

    cout << "Insert number of rows of second matrix: " << endl;
    cin >> a;

    cout << "Insert number of column second matrix: " << endl;
    cin >> b;

    if (y != a)
    {
        cout << "The order of the matrices cannot be multiplied" << endl;
    }
    else
    {
        cout << "Insert elements of the second matrix: " << endl;
        for (row = 0; row < a; row++)
        {
            for (col = 0; col < b; col++)
            {
                cin >> mat2[row][col];
            }
        }

        for (row = 0; row < x; row++)
        {
            for (col = 0; col < b; col++)
            {
                for (z = 0; z < a; z++)
                {
                    sum = sum + mat1[row][z] * mat2[z][col];
                }
                mul[row][col] = sum;
                sum = 0;
            }
        }
    }

    cout << "Multiplication of matrices is : " << endl;
    for (row = 0; row < x; row++)
    {
        for (col = 0; col < b; col++)
        {
            cout << mul[row][col] << endl;
        }
        cout << "\n"
             << endl;
    }

    return 0;
}