#include <iostream>
#include <vector>

enum butt
{
    small,
    medium,
    large
};

class maimuna
{
public:
    maimuna(): b(medium) {};
    maimuna(butt b1) : b(b1) {}
    bool operator==(maimuna &m)
    {
        return b == m.b;
    }

private:
    butt b;
};

template <typename T>
class Set
{
public:
    Set() : size(0), elements(nullptr){};
    void add(T e)
    {
        if (size == 0)
            elements = new T[1];
        if (contains(e))
        {
            return;
        }
        size++;
        T *elements1 = new T[size];
        for (int i = 0; i < size - 1; i++)
        {
            elements1[i] = elements[i];
        }
        elements1[size - 1] = e;
        delete[] elements1;
        elements = elements1;
    }
    bool contains(T n)
    {
        for (int i = 0; i < size; i++)
        {
            if (n == elements[i])
                return true;
        }
        return false;
    }
    int get_size() { return size; }

private:
    T *elements;
    int size;
};

int main()
{

    std::vector<int> v;
    Set<maimuna> s;
    maimuna m1(small), m2(medium), m3(large);
    s.add(m1);
    s.add(m2);
    s.add(m3);
    std::cout << s.get_size() << std::endl;

    return 0;
}