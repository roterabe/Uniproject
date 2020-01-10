#include <iostream>
#include <vector>
#include <cmath>

template <typename T, typename T1>
class Poly
{
public:
    Poly(T* _coeff, int _order)
    {
        order = _order;
        coeff = new T[order + 1];
        for (int i = 0; i <= order; i++)
        coeff[i] = _coeff[i];
    }
    ~Poly()
    {
        delete[] coeff;
    }
    T1 evaluate(T1 x)
    {
        T1 sum = 0;
        for (int i = 0; i <= order; i++)
        {
            sum += coeff[i] * pow(x, order - i);
        }
        return sum;
    } 
    int get_order() {return order;}
private:
    T* coeff;
    int order;
};

int main()
{
    int a[] = {1, 3, 2};
    Poly<int, float> P(a, 2);
    std::cout << P.evaluate(2) << std::endl;
    return 0;
}