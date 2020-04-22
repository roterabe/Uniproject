#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> A;
    int diff = 0, smallest = 0, target = 0;

    for (int i = 0; i < N; i++)
    {
        int k = 0;
        cin >> k;
        A.push_back(k);
    }
    int min = A[0], max = A[0];
    for (auto e : A)
    {
        if (min > e)
            min = e;
        if (max < e)
            max = e;
    }
    diff = max - min;
    int check = 0;
    
    if (diff > A[0])
        check = pow((diff - A[0]), 2);
    else if (diff < A[0])
        check = pow((A[0] - diff), 2);
    else if (diff == A[0])
        check = pow((A[0] - diff), 2);
    for (int i = 0; i < N; i++)
    {
        if (diff > A[i])
            smallest = pow((diff - A[i]), 2);
        else if (diff < A[i])
            smallest = pow((A[i] - diff), 2);
        else if (diff == A[i])
            smallest = pow((A[i] - diff), 2);
        
        if (smallest <= check)
        {
            check = smallest;
            target = A[i];
        }
    }

    for (int k = 0; k < N; k++)
    {
        if (target == A[k])
        {
            cout << k << " ";
        }
    }
    return 0;
}