#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(100); // adjacency list of graph
vector<bool> visited(100);
vector<int> ans;
vector<vector<int>> a(100); // Vector with limit of 100 points.

void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < a[v].size(); i++)
    {
        if (!visited[a[v][i]])
            dfs(a[v][i]);
    }
    ans.push_back(v);
}

void dfs1(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs1(u);
    }
    ans.push_back(v);
}

void topological_sort(vector<int> items)
{
    ans.clear();
    for (auto i : items)
    {
        if (!visited[i])
            dfs1(i);
    }
    reverse(ans.begin(), ans.end());
}

void print(vector<int> p)
{
    for (auto e : p)
    {
        cout << e << " ";
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
    vector<int> items;

    while (c != 0 || c1 != 0)
    {
        if (r1 == 0)
        {
            break;
        }
        cin >> c >> c1;
        a[c].push_back(c1);
        a[c1].push_back(c);
        adj[c].push_back(c1);
        items.push_back(c);

        r1 -= 1;
    }

    for (int v = 0; v < n; v++)
    {
        sort(a[v].begin(), a[v].end());
        sort(adj[v].begin(), adj[v].end());
    }

    topological_sort(items);
    print(ans);
    ans.clear();
    visited.assign(visited.size(), false);
    dfs(i);
    cout << endl;
    print(ans);
}