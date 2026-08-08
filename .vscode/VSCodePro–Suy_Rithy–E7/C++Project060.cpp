#include <iostream>

using namespace std;

int main()
{
    int x, y, r, c, mat1[100][100], mat2[100][100], sum[200][200];
    cout << "Addition of two Matrices \n"
         << endl;

    cout << "Insert number of rows: " << endl;
    cin >> x;

    cout << "Insert number of columns: " << endl;
    cin >> y;

    cout << "Insert elements of first matrix: " << endl;
    for (r = 0; r < x; r++)
    {
        for (c = 0; c < y; c++)
        {
            cin >> mat1[r][c];
        }
    }

    cout << "Insert elements of second matrix: " << endl;
    for (r = 0; r < x; r++)
    {
        for (c = 0; c < y; c++)
        {
            cin >> mat2[r][c];
        }
    }

    for (r = 0; r < x; r++)
    {
        for (c = 0; c < y; c++)
        {
            sum[r][c] = mat1[r][c] + mat2[r][c];
        }
    }

    cout << "The result of matrix is: " << endl;
    for (r = 0; r < x; r++)
    {
        for (c = 0; c < y; c++)
        {
            cout << sum[r][c] << endl;
        }
        cout << "\n"
             << endl;
    }

    return 0;
}