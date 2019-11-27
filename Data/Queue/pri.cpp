// Max-Heap data structure in C++
#include <iostream>
#include <vector>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;
    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}
void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);
    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}
void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

void printBin(vector<int> &hT)
{
    int i = 0;
    cout << hT[i] << '\n';
    int cnt = 0;
    int z = 2;
    for (i = 1; i < hT.size(); i++)
    {
        cnt += 1;
        cout << hT[i] << " ";
        if (cnt % z == 0)
        {
            cout << '\n';
            z += 2;
        }
    }
}

int main()
{
    vector<int> heapTree;
    insert(heapTree, 10);
    printArray(heapTree);
    insert(heapTree, 30);
    printArray(heapTree);
    insert(heapTree, 20);
    printArray(heapTree);
    insert(heapTree, 5);
    printArray(heapTree);
    insert(heapTree, 11);
    cout << "Max-Heap array: ";
    printArray(heapTree);
    //deleteNode(heapTree, 20);
    cout << "After deleting an element: ";
    printArray(heapTree);
    printBin(heapTree);
}
