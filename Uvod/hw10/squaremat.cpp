#include <iostream>
using namespace std;

int main()
{
    // Predefined arrays (calculating to 10x10 max)
    int row1, col1, row2, col2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> col1;

    int a[row1][col1];

    // Storing elements of first matrix.
    cout << endl
         << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < row1; ++i)
        for (int j = 0; j < col1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Go through main elements from 2nd diagonal
    for (int i = 0; i < row1; i++)
    {
            cout << a[i][col1 - i - 1] << " ";
    }

    return 0;
}