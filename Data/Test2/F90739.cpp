#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename K, typename V>
class Map
{
    class Pair
    {
    public:
        Pair(const K &k = K(), const V &v = V()) : Key(k), Value(v){};
        const K &returnKey() const
        {
            return Key;
        }
        void Putkey(const K &k)
        {
            Key = k;
        }
        const V &returnVal() const
        {
            return Value;
        }
        void Putval(const V &v)
        {
            Value = v;
        }

    private:
        K Key;
        V Value;
    };

public:
    typedef typename list<Pair>::iterator It;

    void print();

    int size()
    {
        return Cont.size();
    }
    It begin()
    {
        Cont.begin();
    }
    It end()
    {
        Cont.end();
    }
    void erase(const K &k)
    {
        for (It p = Cont.begin(); p != Cont.end(); p++)
        {
            if (p.returnKey() == k)
            {
                Cont.erase(p);
            }
        }
    }
    void erase(const It &pos)
    {
        Cont.erase(pos);
    }
    bool empty()
    {
        return size() == 0;
    }
    It find(const K &k)
    {
        for (It p = Cont.begin(); p != Cont.end(); p++)
        {
            if (p.returnKey() == k)
                return p;
        }
        return end();
    }
    It put(const K &k, const V &v)
    {
        Pair NPair = Pair(k, v);
        It p = Cont.begin();
        while (p != Cont.end())
        {
            Pair currentPair = *p;
            if (currentPair.returnKey() == k)
            {
                *p = NPair;
                return p;
            }
            p++;
        }
        Cont.insert(p, NPair);
        return p;
    }

private:
    list<Pair> Cont;
};

template <typename K, typename V>
void Map<K, V>::print()
{
    Map<int, int>::Pair nPair;
    cout << setw(6) << "Items" << setw(11) << "Numbers" << endl;
    for (It p = Cont.begin(); p != Cont.end(); p++)
    {
        nPair = *p;
        cout << setw(4) << nPair.returnKey() << setw(10) << nPair.returnVal() << endl;
    }
}

template <typename T>
void histogram(vector<T> Vec, Map<T, T> &M2)
{
    vector<T> newVec;
    int cont = 0;
    int ncont = 0;
    int count = 1;
    for (int i = 0; i < Vec.size(); i++)
    {
        cont = Vec[i];
        if (cont == ncont)
        {
            count++;
            M2.put(cont, count);
            M2.erase(0);
        }
        else
        {
            count = 1;
            M2.put(cont, count);
        }
        ncont = Vec[i];
    }
}

int main()
{
    Map<int, int> M2;
    int S = 0;
    cout << "Please enter size:"
         << "\n";
    cin >> S;
    vector<int> elem(S);
    int input = 0;
    for (int i = 0; i < S; i++)
    {
        cin >> input;
        elem.push_back(input);
    }
    histogram(elem, M2);
    M2.print();
}