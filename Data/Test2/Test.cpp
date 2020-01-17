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
	Map<K, V>::Pair nPair;
	cout << "[ ";
	for (It p = Cont.begin(); p != Cont.end(); p++)
	{
		nPair = *p;
		cout << nPair.returnVal() << " ";
	}
	cout << "]";
}

int main()
{
	Map<int, char> M;
	vector<char> Mem;
	cout << "Enter string: "
		 << "\n";
	string input;
	cin >> input;
	cout << "Enter number of non-repeating elements: "
		 << "\n";
	int k = 0;
	cin >> k;
	cout << "shsh";

	for (int i = 0; i < input.size() - 1; i++)
	{
		char rem = input[i];
		//char save = rem;

		Mem.push_back(rem);
		for (int j = 1; j < input.size(); j++)
		{
			if (rem == input[j])
			{
				Mem.pop_back();
			}
		}
	}
	for (int i = 0; i < Mem.size(); i++)
	{
		M.put(i, Mem[i]);
	}
	M.print();

	return 0;
}