#include <iostream>
using namespace std;

int main()
{
    // Predefined arrays (calculating to 10x10 max)
    int row1, col1, row2, col2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> row2 >> col2;

    int a[row1][col1], b[row2][col2], result[col1][col2];

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (col1 != row2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> row1 >> col1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> row2 >> col2;
    }

    // Storing elements of first matrix.
    cout << endl
         << "Enter elements of matrix 1:" << endl;
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl
         << "Enter elements of matrix 2:" << endl;
    for (i = 0; i < row2; ++i)
        for (j = 0; j < col2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Initializing elements of matrix "result" to 0.
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col2; ++j)
        {
            result[i][j] = 0;
        }

    // multiplying matrix a and b and storing in array result.
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col2; ++j)
            for (k = 0; k < col1; ++k)
            {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }

    // Displaying the result of two matrix multiplication.
    cout << endl
         << "Output Matrix: " << endl;
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col2; ++j)
        {
            cout << " " << result[i][j];
            // Give new line when no more nums are available on row
            if (j == col2 - 1)
                cout << endl;
        }

    return 0;
}