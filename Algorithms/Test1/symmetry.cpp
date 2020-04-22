#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void calc(vector<int> A, vector<int> B, int M, int N)
{
    int i = 0, j = 0;
    while (i < M && j < N)
    {
        if (A[i] < B[j])
        {
            cout << A[i] << " ";
            i++;
        }
        else if (B[j] < A[i])
        {
            cout << B[j] << " ";
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < M)
    {
        cout << A[i] << " ";
        i++;
    }
    while (j < N)
    {
        cout << B[j] << " ";
        j++;
    }
}

void print(vector<int> a)
{
    for (auto e : a)
    {
        cout << e << " ";
    }
    cout << "\n";
}

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N = 0, M = 0;
    cin >> M >> N;

    vector<int> A;
    vector<int> B;

    for (int i = 0; i < M; i++)
    {
        int k = 0;
        cin >> k;
        A.push_back(k);
    }

    for (int i = 0; i < N; i++)
    {
        int k = 0;
        cin >> k;
        B.push_back(k);
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    calc(A, B, M, N);

    return 0;
}