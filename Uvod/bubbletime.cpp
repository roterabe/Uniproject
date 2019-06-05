#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
#include <chrono>

using namespace std;

void print(vector<int> k)
{
    for (auto e : k)
    {
        cout << e << " ";
    }
}

int rand_int()
{
    return rand() % 1000 + 1;
}



int main()
{

    vector<int> k = vector<int>();
    int sz = 0;
    cout << "enter size: " << endl;
    cin >> sz;
   // for (int i = 0; i < sz; i++)
    //{
    int num = 1000;
    for (int j = sz; j > 0; j--)
    {
        
    
        // int input = 0;
        //cin >> input;
        k.push_back(num);
        num--;
    }
    //}
    //time_t t0, t1;
    //clock_t c0, c1;

    //t0 = clock();
    //c0 = clock();
    //srand(time(NULL));

    auto start = std::chrono::high_resolution_clock::now();

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
    auto stop = std::chrono::high_resolution_clock::now();
    //c1 = clock();
    //t1 = clock();
    //cout << "Elapsed wall clock time: " << ((long)(t1 - t0)) << endl;
    //cout << "Elapsed wall clock time :" << (double)(c1 - c0) / CLOCKS_PER_SEC << endl
    //  << endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    print(k);
    cout << endl;

    return 0;
}