
// A Quick implementation of BFS using
// vectors and queue
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<bool> v;
vector<vector<int>> g;
vector<int> level;

void edge(int a, int b)
{
    g[a].pb(b);
}

void bfs(int u)
{
    queue<int> q;

    q.push(u);
    v[u] = true;
    level[u] = 1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        cout << f << " ";

        // Enqueue all adjacent of f and mark them visited
        for (auto i = g[f].begin(); i != g[f].end(); i++)
        {
            int b = g[f][*i];

            if (!v[*i])
            {
                q.push(*i);
                level[b] = level[u] + 1;
                v[*i] = true;
            }
        }
    }

    cout << "Nodes"
         << "    "
         << "Level" << endl;
    for (int i = 0; i < g.size() + 1; i++)
        cout << " " << i << "   -->   " << level[i] << endl;
}

// Driver code
int main()
{
    int n, e, src;
    cin >> n >> e >> src;
    level.resize(n + 1);

    v.assign(n + 1, false);
    g.assign(n + 1, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge(a, b);
    }

    /* for (int i = 0; i < n; i++)
    {
        if (!v[i]) */
    bfs(src);

    return 0;
}
