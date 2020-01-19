#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename K, typename V>
class Map
{
public:
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

    typedef typename vector<Pair>::iterator It;

    void print();

    int size()
    {
        return Cont.size();
    }
    It begin()
    {
        return Cont.begin();
    }
    It end()
    {
        return Cont.end();
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
            if ((*p).returnKey() == k)
                return p;
        }
        return end();
    }
    V getVal(const K &k)
    {
        for (It p = Cont.begin(); p != Cont.end(); p++)
        {
            if ((*p).returnKey() == k)
            {
                return (*p).returnVal();
            }
        }
        return 0;
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
    vector<Pair> Cont;
};

template <typename K, typename V>
void Map<K, V>::print()
{
    Map<K, V>::Pair nPair;
    cout << setw(6) << "Items" << setw(11) << "Numbers" << endl;
    for (It p = Cont.begin(); p != Cont.end(); p++)
    {
        nPair = *p;
        cout << setw(4) << nPair.returnKey() << setw(10) << nPair.returnVal() << endl;
    }
}

template <typename T, typename E>
void function(vector<T> Vec, Map<T, E> &M)
{
    string word = "Test";
    string newword = "Test1";
    int count = 0;
    for (int i = 0; i < Vec.size(); i++)
    {
        //word = Vec[i];
        //M.put(word, count);
        newword = Vec[i];
        if (M.find(newword) != M.end())
        {
            count = M.getVal(newword);
            count++;
            M.put(newword, count);
        }
        else if (M.find(newword) == M.end())
        {
            count = 1;
            M.put(newword, count);
        }
    }
}

int main()
{
    Map<string, int> M;
    int S;
    cout << "Please enter size:"
         << "\n";
    cin >> S;
    int rep = 0;
    cout << "Please enter amount of words to print: "
         << "\n";
    cin >> rep;
    vector<string> words(S);
    string input;
    cout << "Please enter words accordingly: "
         << "\n";
    for (int i = 0; i < S; i++)
    {
        cin >> input;
        words.push_back(input);
    }
    function(words, M);
    M.print();
}