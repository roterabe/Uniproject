#include <iostream>
#include <vector>
#include <time.h>
#include <sys/types.h>

using namespace std;

/*int rand_int(){
    return rand() % 20 + 1;
}*/

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

void insertionSort(int arr[], int n)
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
    time_t t0, t1;

    clock_t begin = clock();

    int k = 10000;
    int rev_count = 10000;
    int arr[k];

    for (int i = 0; i < k; i++)
    {
        arr[i] = rev_count;
        rev_count--;
    }

    insertionSort(arr, k);
    clock_t end = clock();

    double answer = (double)(end - begin) / CLOCKS_PER_SEC;

    //std::cout << "Elapsed wall clock time: " << ((long) (t1 - t0)) << endl;
    std::cout << "Elapsed wall clock time :" << answer << endl;
    print(arr, k);
    cout << endl;
    return 0;
}
