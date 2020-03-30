#include <iostream>

using namespace std;

int const size = 120;

template <typename T>
class queue
{
public:
    queue();  // constructor
    ~queue(); // destructor
    queue(queue const &);
    queue &operator=(queue const &); // assigns
    void push(T const &);            // adds element to the end of the queue
    int pop();                       // removes first element in queue
    void print();                    // print elements in queue
    T front()                        // first element in queue
    {
        if (isEmpty())
        {
            cout << "Empty queue access - err" << endl;
            return -1;
        }

        return queueArr[front];
    }
    bool isEmpty() const { return (n == 0); }
    int queueSize() const { return (n); }

private:
    int front, rear, n;
    T *queueArr;
    void copyqueue(queue const &);
};

void result(queue<int> res, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
}

int main()
{
    int n = 0;
    int size = 0;
    cout << "Please enter the number you shall be modifying: ";
    cin >> n;
    cout << "Please enter how many times you'd like to repeat the process: ";
    cin >> size;
    if (size <= 3)
    {
        cout << "error - size should be \" > 3 \" & \" < 120 \" " << endl;
        return -1;
    }
    int cnt = 1;
    queue<int> alg;
    alg.push(n);
    queue<int> res;
    res.push(n);
    for (int i = 0; i < size; i++)
    {

        // Follow the progression by using a second queue
        if (cnt == 1)
        {
            alg.push(alg.front() + 1);
            res.push(alg.front() + 1);
            cnt = 2;
        }
        else if (cnt == 2)
        {
            alg.push(2 * alg.front());
            res.push(2 * alg.front());
            alg.pop();
            cnt = 1;
        }
    }

    result(res, size);

    return 0;
}

//Construct
template <typename T>
queue<T>::queue()
{
    queueArr = new T[size];
    n = 0;
    front = 0;
    rear = 0;
}

//Destructor
template <typename T>
queue<T>::~queue()
{
    delete[] queueArr;
}

template <typename T>
queue<T>::queue(queue<T> const &r)
{
    copyqueue(r);
}

//Assign operator
template <typename T>
queue<T> &queue<T>::operator=(queue<T> const &r)
{
    if (this != &r)
    {
        delete[] queueArr;
        copyqueue(r);
    }

    return *this;
}

//Add element at end of queue
template <typename T>
void queue<T>::push(T const &x)
{
    if (n == size)
    {
        cout << "Not possible \n";
    }
    else
    {
        queueArr[rear] = x;
        n++;
        rear++;
        rear = rear % size;
    }
}

//Remove element at beggining of queue
template <typename T>
int queue<T>::pop()
{
    if (n > 0)
    {
        T x = queueArr[f];
        n--;
        front++;
        front = front % size;
        return 1;
    }
    else
        return 0;
}

template <typename T>
void queue<T>::copyqueue(queue<T> const &r)
{
    queueArr = new T[size];

    for (int i = 0; i < size; i++)
    {
        queueArr[i] = r.queueArr[i];

        n = r.n;
        front = r.front;
        rear = r.rear;
    }
}


template <typename T>
void queue<T>::print()
{
    T x;
    while (pop(x))
        cout << x << " ";
    cout << endl;
}