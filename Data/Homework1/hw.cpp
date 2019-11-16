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
    double n = 0;
    int size = 0;
    cout << "Please enter the number you shall be modifying: ";
    cin >> n;
    cout << "Please enter how many times you'd like to repeat the process: ";
    cin >> size;
    if (size <= 3)
    {
        cout << "error - size should be \" > 3 \" & \" < 120 \"" << endl;
        return -1;
    }
    int cnt = 1;
    queue<double> alg;
    alg.push(n);
    queue<double> res;
    res.push(n);
    for (int i = 0; i < size; i++)
    {

        // Follow the progression by using a second queue
        if (cnt == 1)
        {
            alg.push(alg.Front() + 1);
            res.push(alg.Front() + 1);
            cnt = 2;
        }
        else if (cnt == 2)
        {
            alg.push(2 * alg.Front());
            res.push(2 * alg.Front());
            alg.pop();
            cnt = 1;
        }
    }

    result(res, size);

    return 0;
}