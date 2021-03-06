#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <set>

#define MAX 1000

using namespace std;

vector<vector<int>> g(MAX);
vector<vector<int>> c(MAX);
vector<int> U(MAX);
vector<int> d(MAX);
vector<int> p(MAX);
vector<int> vertices;
int res = 0;

void dijkstra(int r, int n)
{
    int v, w, min, i, j;
    for (i = 1; i <= n; i++)
    {
        U[i] = 0;
        p[i] = r;
        d[i] = INT_MAX;
    }
    d[r] = p[r] = 0;
    for (i = 1; i <= n; i++)
    {
        v = 0;
        min = INT_MAX;
        for (j = 1; j <= n; j++)
            if (U[j] == 0 && d[j] < min)
            {
                v = j;
                min = d[j];
            }
        U[v] = 1;
        for (j = 1; j <= g[v][0]; j++)
        {
            w = g[v][j];
            if (U[w] == 0 && d[v] + c[v][w] < d[w])
            {
                d[w] = d[v] + c[v][w];
                p[w] = v;
            }
        }
    }
}

int main()
{
    int utex, vertex, weight, size, edge, i, j;

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
        cin >> utex >> vertex;
        weight = 1;
        g[utex][++g[utex][0]] = vertex;
        g[vertex][++g[vertex][0]] = utex;
        c[utex][vertex] = c[vertex][utex] = weight;
        if (std::find(vertices.begin(), vertices.end(), utex) == vertices.end())
        {
            vertices.push_back(utex);
        }
        if (std::find(vertices.begin(), vertices.end(), vertex) == vertices.end())
        {
            vertices.push_back(vertex);
        }
    }

    for (auto s : vertices)
        dijkstra(s, size);

    for(auto item : vertices)
        if (res < d[item])
            res = d[item];
    cout << res;
    return 0;
}
