#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void calc(vector<int> elements, int n, int &cnt, int &turn)
{
    if (n > 1)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (elements[j] > elements[j + 1])
            {
                cnt += 1;
            }
        }
        cnt += 1;
        for (int i = n - 1; i > 1; i--)
        {
            if (elements[i] > elements[i - 1])
            {
                turn += 1;
            }
        }
        turn += 1;
    }
    if (cnt > turn)
    {
        cnt = turn;
    }
    if (n == 1)
    {
        cnt = 1;
    }
}

void result(int cnt, int res, int n)
{
    if (cnt < n / 2)
    {
        res = 1;
        cout << cnt << "\n";
        cout << res << "\n";
    }
    else if (cnt >= n / 2)
    {
        res = 0;
        cout << cnt << "\n";
        cout << res << "\n";
    }
}

int main()
{
    int n = 0;
    int cnt = 0;
    int res = 0;
    int turn = 0;

    //Take user input for array size.
    cin >> n;

    vector<int> elements;

    for (int i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;
        elements.push_back(input);
    }

    calc(elements, n, cnt, turn);
    result(cnt, res, n);

    /*if (cnt < n / 2 && res == 0)
            {
                cout << "Broken" << endl;
                ;
                print(arr, n);
            }*/

    return 0;
}