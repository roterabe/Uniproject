#include <iostream>

using namespace std;

int f1(int a[], int n, int c)
{
    int cnt = 0;
    int i, j, suma = 0;
    for (i = 1;; i = c * i)
    {
        if (i >= n)
            return cnt;
        for (j = i; j < i + c; j++)
        {
            cnt++;
            suma += a[i];
            
        }
    }
}

int main()
{
    int n = 298;
    int c = 5;
    int a[n];
    int k = f1(a, n, c);
    cout << "\n" << k << "\n";
    return 0;
}