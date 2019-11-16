#include <iostream>
#include <queue>

using namespace std;

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
    int n = 1;
    int size = 7;
    int cnt = 1;
    queue<int> alg;
    alg.push(n);
    queue<int> res;
    res.push(n);
    for (int i = 0; i < size; i++)
    {

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