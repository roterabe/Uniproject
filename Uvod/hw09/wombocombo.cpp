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

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

void insertionSort1(int arr[], int n)
{
    int Buf, j, check;
    for (int i = 1; i < n; i++)
    {
        Buf = arr[i];
        j = i - 1;

        check = binarySearch(arr, Buf, 0, j);

        while (j >= check)
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

void print(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int k = 10000;
    int arr[k];
    int arr1[k];
    int rev_count = 10000;

    for (int i = 0; i < k; i++)
    {
        arr[i] = rev_count;
        arr1[i] = rev_count;
        rev_count--;
    }

    
    clock_t c0, c1, c2, c3;

    // t0 = time(NULL);
    c0 = clock();

    insertionSort(arr, k);

    c1 = clock();

    c2 = clock();

    insertionSort1(arr1, k);

    c3 = clock();

    cout << "Elapsed wall clock time for insertion sort only :" << (double)(c1 - c0) / CLOCKS_PER_SEC << endl;
    cout << "Elapsed wall clock time for insertion sort with binary search :" << (double)(c3 - c2) / CLOCKS_PER_SEC << endl;
    //print(arr, k);
    //cout << endl;

    return 0;
}
