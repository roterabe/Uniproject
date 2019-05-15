#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int Buf, j;
    for (int i = 1; i < n; i++)
    {
        Buf = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > Buf)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = Buf;
    }
}

int rand_int()
{
    return rand() % 20 + 1;
}

int main()
{

    int k = 10000;
    int arr[k];
    int rev_count = 10000;

    for (int i = 0; i < k; i++)
    {
        arr[i] = rev_count;
        rev_count--;
    }

    time_t t0, t1;
    clock_t c0, c1;

    // t0 = time(NULL);
    c0 = clock();

    insertionSort(arr, k);

    c1 = clock();
    // t1 = time(NULL);

    //reverse(a.begin(), a.end());
    //srand ( time(NULL) );

    //cout << "Elapsed wall clock time: " << ((long) (t1 - t0)) << endl;
    cout << "Elapsed wall clock time :" << (double)(c1 - c0) / CLOCKS_PER_SEC << endl;

    return 0;
}
