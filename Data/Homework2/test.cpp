#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <typename T>
class Bin
{
private:
    vector<int> A;
    // Recursive Heapify-down algorithm
    // the node at index pos and its two direct children
    // violates the heap property

    // Recursive Heapify-up algorithm

public:
    typedef typename vector<T>::iterator it;
    void swap(it &one, it &two)
    {
        T temp = *one;
        *one = *two;
        *two = temp;
    }
    T PARENT(const int pos)
    {
        return (pos - 1) / 2;
    }
    it convert(int pos)
    {
        return A.begin() + pos;
    }
    int reverse(it &pos)
    {
        return pos - A.begin();
    }

    T RETEL(T pos)
    {
        return A[pos];
    }

    const int LEFT(T pos)
    {
        return (2 * pos + 1);
    }

    const int RIGHT(T pos)
    {
        return (2 * pos + 2);
    }
    // return size of the heap
    T size()
    {
        return A.size();
    }

    bool hasLeft(int pos)
    {
        if (LEFT(pos) <= A.size())
            return true;
        else
            return false;
    }

    bool hasRight(int pos)
    {
        if (RIGHT(pos) <= A.size())
            return true;
        else
            return false;
    }
    // function to check if heap is empty or not
    bool empty()
    {
        return size() == 0;
    }

    bool isRoot(int pos)
    {
        if (pos == 0)
            return true;
        else
            return false;
    }

    // add key into the heap
    void add(T key)
    {
        // add the new element to the end of the vector
        A.push_back(key);
    }

    void remove()
    {
        A.pop_back();
    }

    T last()
    {
        if (size() == 0)
        {
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow)");
        }
        else
        {
            return A[A.size() - 1];
        }
    }

    T root()
    {
        // if heap has no elements, throw an exception
        if (size() == 0)
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow)");
        else
            // else return the top (first) element
            return A.at(0); // or return A[0];
    }
    void printA()
    {
        for (auto e : A)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
};

template <class T>
class PriorityQueue
{
private:
    Bin<T> B;
    typedef typename Bin<T>::it it;
    void swapp(it &one, it &two)
    {
        B.swap(one, two);
    }

    void heapify_down(T pos)
    {
        // get left and right child of node at index pos
        it left = B.convert(B.LEFT(pos));
        it right = B.convert(B.RIGHT(pos));
        it pos1 = B.convert(pos);
        it largest = B.convert(pos);

        // compare B[pos] with its left and right child
        // and find largest value
        if (left < B.convert(size()) && *left > *pos1)
            largest = left;

        if (right < B.convert(size()) && *right > *largest)
            largest = right;

        // swap with child having greater value and
        // call heapify-down on the child
        if (largest != pos1)
        {
            swap(pos1, largest);
            heapify_down(*largest);
        }
    }

    void heapify_up(int pos)
    {
        it parpos = B.convert((pos - 1) / 2);
        it pos1 = B.convert(pos);
        int index = B.reverse(pos1);
        while (!B.isRoot(index))
        {
            cout << *parpos;
            cout << "swag";
            if (*parpos < *pos1)
            {
                cout << "yolo";
                swapp(parpos, pos1);
                parpos = pos1;
            }
            else
            {
                break;
            }
        }
    }
    /* {
        it parpos = B.convert((pos - 1) / 2);
        cout << *parpos;
        it pos1 = B.convert(pos);
        int comp = *parpos;
        int comp1 = *pos1;
        // check if node at index pos and its parent violates
        // the heap property
        if (comp > comp1)
        {
            cout << "NOICE";
            // swap the two if heap property is violated
            swapp(pos1, parpos);
            int index = B.reverse(parpos);
            // call Heapify-up on the parent
            heapify_up(index);
        }
    }*/

public:
    T size()
    {
        return B.size();
    }
    bool empty()
    {
        return size() == 0;
    }
    void insert(int key)
    {
        B.add(key);
        int pos = B.size() - 1;
        int changepos = pos;
        while (!B.isRoot(changepos))
        {
            //cout << *parpos;
            //cout << "swag";
            cout << changepos << " ";
            it parpos = B.convert(changepos / 2);
            it pos1 = B.convert(changepos);
            //cout << *parpos << " ";
            if (*parpos > *pos1)
            {
                // cout << "yolo";
                swapp(parpos, pos1);
                changepos = B.reverse(parpos);
                //pos1 = parpos;
            }
            else
            {
                break;
            }
        }
    }
    void removeMin()
    {
        it roo = B.convert(B.root());
        it last = B.convert(B.size());
        it leftofroot = B.convert(B.LEFT(B.root()));
        if (size() == 1)
            B.remove();
        else
        {
            swap(roo, last);
            B.remove();
            if (B.hasLeft(B.root()))
                heapify_down(*leftofroot);
        }
    }
    T min()
    {
        return B.root();
    }
    void print()
    {
        B.printA();
    }
};

int main()
{
    PriorityQueue<int> pq;
    int size = 0;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        
    }

    pq.insert(10);
    pq.insert(8);
    pq.insert(9);
    pq.insert(11);
    pq.insert(12);
    cout << pq.size() << "\n";
    cout << pq.min() << "\n";
    pq.print();

    return 0;
}

/*
Съответно за full binary tree:
    left(p) – връща лявото дете на възела на позиция p; - yes
    right(p) – връща дясното дете на възела на позиция p; - yes
    parent(p) – връща родителя на възела на позиция p; - yes
    root() – връща върха на Хипа; - yes
    last() – връща последният добавен елемент в Хипа; - yes
    isRoot(p) – връща true, ако възела на позиция p е корен и false, в противен случай; - yes
    hasLeft(p) – връща true, ако възела на позиция p има ляв наследник и false, в противен случай; - yes
    hasRight(p) – връща true, ако възела на позиция p има десен наследник и false, в противен случай; - yes
    add(e) – Добавя нов елемент към Хипа и връща нов външен възел v съхраняващ елемента e, така че полученият Хип да бъде пълно двоично дърво с последен възел v. - yes
    remove() – Премахва последния възел на Хипа и връща неговият елемент. - yes
И за priority queue:

    size() – Връща броя на елементите в приоритетната опашка. - yes
    empty() – Връща true, ако приоритетната опашка е празна и false, в противен случай. - yes
    insert(e) - Вмъква елемента e в приоритетната опашка; - yes
    min() – Връща елемента с най-малък ключ(стойност), т.е. елемент, чийто ключ(стойност) е по-малък от или равен на този на всеки друг елемент в приоритетната опашка. - yes 
    removeMin() - Премахване от приоритетната опашка елемента с най-малък ключ (стойност). - 

*/