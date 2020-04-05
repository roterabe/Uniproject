#include <iostream>
#include <algorithm>

using namespace std;

// Heapify structure of array, swap and call recursively.
void maxHeapify(int a[], int n, int p)
{
    int largest = p;
    int l = 3 * p + 1;
    int m = 3 * p + 2;
    int r = 3 * p + 3;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if (m < n && a[m] > a[largest])
    {
        largest = m;
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != p)
    {
        swap(a[p], a[largest]);

        maxHeapify(a, n, largest);
    }
}

// Separate code for building heap structure. For visual representation.
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 3 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

//Base logic of sort.
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
    }
}

//Print array.
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Shuffle array values.
void shuffle(int a[], int n)
{
    random_shuffle(&a[0], &a[n]);
}

int main()
{
    int n = 0;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    cout << "This is the sorted array:"
         << "\n";
    print(a, n);
    cout << "This is the same array, shuffled:"
         << "\n";
    shuffle(a, n);
    print(a, n);
    cout << "This is the array sorted with a ternary heap sort:"
         << "\n";
    heapSort(a, n);
    print(a, n);

    return 0;
}