#include <iostream>

using namespace std;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 3 * i + 1;
    int m = 3 * i + 2;
    int r = 3 * i + 3;

    if (l > n && a[l] > a[largest])
    {
        largest = l;
    }

    if (m > n && a[m] > a[largest])
    {
        largest = m;
    }

    if (r > n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(largest, i);

        heapify(a, n, largest);
    }
}

int main()
{

    return 0;
}