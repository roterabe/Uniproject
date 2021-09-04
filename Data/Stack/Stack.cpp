#include <iostream>

const int NUM = 1000;

template <typename O>
class ArrayStack
{
private:
    int n;
    O *arr;
    int t;

public:
    ArrayStack(int cap = NUM)
    {
        n = cap;
        arr = new O[n];
        t = -1;
    }

    ArrayStack(const ArrayStack &st);
    ArrayStack &operator=(const ArrayStack &st);

    ~ArrayStack()
    {
        delete[] arr;
    }

    void push(const O &obj)
    {
        if (size() == n)
        {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        t++;
        arr[t] = obj;
    }

    O pop()
    {
        if (isEmpty())
        {
            std::cout << "Access to empty stack" << std::endl;
            return 1;
        }
        return arr[t--];
    }
    O &top() const
    {
        return arr[t];
    }
    bool isEmpty() const
    {
        return (t < 0);
    }

    int size() const
    {
        return (t + 1);
    }

    void print()
    {
        while (!isEmpty())
        {
            std::cout << top();
            pop();
        }
        std::cout << std::endl;
    }
};

template <typename O>
ArrayStack<O>::ArrayStack(const ArrayStack &st)
{
    n = st.n;
    t = st.t;
    arr = new O[n];

    for (int i = 0; i <= t; i++)
    {
        arr[i] = st.arr[i];
    }
}

template <typename O>
ArrayStack<O> &ArrayStack<O>::operator=(const ArrayStack &st)
{
    if (this != &st)
    {
        delete[] arr;
        n = st.n;
        t = st.t;
        arr = new O[n];

        for (int i = 0; i <= t; i++)
        {
            arr[i] = st.arr[i];
        }
    }
    return *this;
}

int main()
{
    ArrayStack<int> A;
    int o = 0;
    std::cin >> o;
    int k = o;
    do
    {
        A.push(o % 2);
        o = o / 2;
    } while (o);

    for (int i = k; i > 0; i /= 2)
    {
        std::cout << A.top() << " ";
        A.pop();
    }
    std::cout << std::endl;

    return 0;
}
