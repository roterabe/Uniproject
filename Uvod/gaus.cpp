#include <iostream>

int main()
{
    int arr[3][3];
    const int a = 0;
    int i = 0;
    int j = 0;
    int k = arr[0][0];
    while (j <= 3)
    {
        arr[i][j] = arr[i][j]/k;
        j++;
    }

    return 0;
}