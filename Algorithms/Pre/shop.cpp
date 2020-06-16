#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <set>

#define MAX 1000

using namespace std;

vector<vector<int>> g(MAX);
vector<vector<int>> c(MAX);
vector<bool> U(MAX);
vector<int> d(MAX);
vector<int> p(MAX);
vector<int> vertices;
int res = 0;

void dijkstra(int src, int n)
{
    int v, w, min, i, j;
    U.assign(U.size(), false);
    p.assign(p.size(), src);
    d.assign(d.size(), INT_MAX);

    d[src] = p[src] = 0;

    for (i = 1; i <= n; i++)
    {
        v = 0;
        min = INT_MAX;
        for (j = 1; j <= n; j++)
            if (U[j] == false && d[j] < min)
            {
                v = j;
                min = d[j];
            }
        U[v] = true;
        for (j = 1; j <= g[v][0]; j++)
        {
            w = g[v][j];
            if (U[w] == false && d[v] + c[v][w] < d[w])
            {
                d[w] = d[v] + c[v][w];
                p[w] = v;
            }
        }
    }
}

int main()
{
    int u, v, weight, size, edge, i, j;

    cin >> size >> edge;

    for (int i = 0; i < g.size(); i++)
    {
        g[i].resize(MAX);
        c[i].resize(MAX);
    }

    for (i = 1; i <= size; i++)
    {
        g[i][0] = 0;
        for (j = 1; j <= size; j++)
            c[i][j] = INT_MAX;
        if (i == j)
            c[i][j] = 0;
    }
    for (int i = 1; i <= edge; i++)
    {
        cin >> u >> v >> weight;
        g[u][++g[u][0]] = v;
        g[v][++g[v][0]] = u;
        c[u][v] = c[v][u] = weight;
        if (std::find(vertices.begin(), vertices.end(), u) == vertices.end())
        {
            vertices.push_back(u);
        }
        if (std::find(vertices.begin(), vertices.end(), v) == vertices.end())
        {
            vertices.push_back(v);
        }
    }

    for (auto s : vertices)
        dijkstra(s, size);

    int parent = 0;
    res = INT_MAX;
    for (auto item : vertices)
        if (res > d[item] && d[item] != 0)
        {
            res = d[item];
            parent = p[item];
        }
    cout << res << " :: " << parent << endl;
    return 0;
}
