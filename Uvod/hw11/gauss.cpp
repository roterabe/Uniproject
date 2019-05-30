#include <iostream>

using namespace std;

int main()
{

    // Predefine array
    int row = 3;
    int col = 4;

    double a[3][4] = {{2.0, 9.0, 0.0, 134.0}, {9.0, -3.0, 9.0, 12.0}, {7.0, 3.0, 5.0, -36.0}};

    for (int i = 0; i < row; i++)
    {
        double first = a[i][i];

        for (int j = i; j < col; j++)
        {

            a[i][j] = a[i][j] / first;

            for (int k = i+1; k < row; k++)
            {
                double f_next = a[k][i];

                for (int l = i; l < col; l++)
                {
                    a[k][l] = a[k][l] - f_next * a[i][l];
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
            if (j == col-1)
                cout << endl;
        }
    }

    cout << endl;
    double x3 = a[2][3];
    double x2 = a[1][3]+(-1*(a[1][2]*x3));
    double x1 = a[0][3] + (-1*(a[0][1]*x2+a[0][2]*x3));

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;
}