/* queue - Circular Array implementation in C++*/
#include <iostream>
using namespace std;
#define MAX_SIZE 120 //maximum size of the array that will store queue.

// Creating a class named queue.
template <typename T>
class queue
{
private:
    T A[MAX_SIZE];
    int front, rear;

public:
    // Constructor - set front and rear as -1.
    // We are assuming that for an empty queue, both front and rear will be -1.
    queue()
    {
        front = -1;
        rear = -1;
    }

    // To check wheter queue is empty or not
    bool IsEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // To check whether queue is full or not
    bool IsFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    // Inserts an element in queue at rear end
    void push(T x)
    {
        //cout << "Enqueuing " << x << " \n";
        if (IsFull())
        {
            cout << "Error: queue is Full\n";
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    // Removes an element in queue from front end.
    void pop()
    {
        //cout << "Dequeuing \n";
        if (IsEmpty())
        {
            cout << "Error: queue is Empty\n";
            return;
        }
        else if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }
    // Returns element at front of queue.
    T Front()
    {
        if (front == -1)
        {
            cout << "Error: cannot return front from empty queue\n";
            return -1;
        }
        return A[front];
    }
    /* 
	   Printing the elements in queue from front to rear. 
	   This function is only to test the code. 
	   This is not a standard function for queue implementation. 
	*/
    void print()
    {
        // Finding number of elements in queue
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        cout << "queue       : ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE; // Index of element while travesing circularly from front
            cout << A[index] << " ";
        }
        cout << "\n\n";
    }

    void swap(T *a, T *b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }

    int partition(T *arr, int low, int high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void sort(T *arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now  
        at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }
    void imp()
    {
        sort(A, front, rear);
    }
};

void result(queue<double> res, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << res.Front() << " ";
        res.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> noice;
    noice.push(9);
    noice.push(7);
    noice.push(10);
    noice.push(3);
    noice.imp();
    noice.print();

    return 0;
}