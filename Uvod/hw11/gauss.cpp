#include <iostream>

using namespace std;

void gauss(int &a, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
    }
}

int main()
{

    // Predefined arrays (calculating to 10x10 max)
    int row, col, i, j, k;

    cout << "Enter rows and columns for matrix: ";
    cin >> row >> col;

    int a[row][col];

    // Fill matrix
    cout << endl
         << "Enter elements of matrix :" << endl;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    return 0;
}