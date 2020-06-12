#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> a(100); // Vector with limit of 100 points.
int used[100];              // Array to mark the points we've passed.

void dfs(int k)
{
    cout << k << " ";
    for (int i = 0; i < a[k].size(); i++)
    {
        if (used[a[k][i]])
            continue;
        used[a[k][i]] = 1;
        dfs(a[k][i]);
    }
}

int main()
{
    int n = 0; // Number of corners.
    int r = 0; // Number of roads.
    cin >> n >> r;

    int i = 0; // First corner.

    cin >> i;

    int c = 1;
    int c1 = 1;
    int r1 = r;

    while (c != 0 || c1 != 0)
    {
        if (r1 == 0)
        {
            break;
        }
        cin >> c >> c1;
        a[c].push_back(c1);
        a[c1].push_back(c);

        r1 -= 1;
    }

    for (int v = 0; v < n; v++)
    {
        sort(a[v].begin(), a[v].end());
    }
    used[i] = 1;
    dfs(i);
}