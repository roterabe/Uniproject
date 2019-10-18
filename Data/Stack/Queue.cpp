#include <iostream>
using namespace std;

int const size = 1000;

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue;
    Queue(Queue const &);
    Queue &operator=(Queue const &);
    void InsertElem(T const &);
    int DeleteElem(T &);
    void print();
    T front();
    {
        if (isEmpty())
        {
            cout << "Access to empty queue!" << endl;
            return 1;
        }
        return queueArr[f];
    }
    bool isEmpty() const
    {
        return (n == 0);
    }
    int queueSize() const
    {
        return (n);
    }

private:
    int f, rear, n;
    T *queueArr;
    void copyQueue(Queue const &);
};

int main()
{
    return 0;
}

template <typename T>
Queue<T>::Queue()
{
    queueArr = new T(size);
    n = 0;
    f = 0;
    rear = 0;
}

template <typename T>
Queue<T>::Queue()
{
    delete[] queueArr;
}

template <typename T>
Queue<T>::Queue(Queue<T> const &r)
{
    copyQueue(r);
}

template <typename T>
Queue<T> &Queue<T>::operator=(Queue<T> const &r)
{
    if (this != &r)
    {
        delete[] queueArr;
        copyQueue(r);
    }
    return *this;
}

template <typename T>
void Queue<T>::InsertElem(T const &x)
{
    if (n == size)
    {
        cout << "Impossible! \n";
    }
    else
    {
        queueArr[rear] = x;
        n++;
        rear++;
        read = rear % size;
    }
}

//To be continued....