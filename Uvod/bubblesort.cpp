#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

void print(vector<int> k)
{
    for (auto e : k)
    {
        cout << e << " ";
    }
}

int main()
{

    vector<int> k = vector<int>();
    int sz = 0;
    cout << "enter size: " << endl;
    cin >> sz;
    for (int i = 0; i < sz; i++)
    {
        int input = 0;
        cin >> input;
        k.push_back(input);
    }

    bool inverted = true;
    while (inverted)
    {
        inverted = false;
        for (int j = 0; j < sz - 1; j++)
        {
            if (k[j + 1] < k[j])
            {
                int buff = k[j];
                k[j] = k[j + 1];
                k[j + 1] = buff;
                inverted = true;
            }
        }
    }
    
    print(k);

    return 0;
}