#include <iostream>
using namespace std;

int square(int n)
{
    int k = 0;
    while (true)
    {
        if (k == n * n)
        {
            return k;
        }
        k++;
    }
}

int main()
{
    int n = 100000;

    cout << square(n) << endl;
}