#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int orders, N = 0;
    cin >> orders >> N;
    vector<int> pizzas;
    vector<int> meat;

    for (int i = 0; i < orders; i++)
    {
        int insert = 0;
        cin >> insert;
        pizzas.push_back(insert);
    }

    for (int i = 0; i < pizzas.size(); i++)
    {
        bool found = false;
        for (int j = i; j < N + i; j++)
        {
            if (pizzas[j] == 0)
                j++;
            if (pizzas[j] < 0)
            {
                meat.push_back(pizzas[j]);
                cout << pizzas[j];
                pizzas[j] = 0;
                /* cout << "\n"
                     << pizzas.size(); */
                found = true;
            }
        }
        if (found == false)
        {
            meat.push_back(0);
        }
    }

    for (auto e : meat)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}