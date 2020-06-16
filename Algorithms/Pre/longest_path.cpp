#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>

using namespace std;

vector<vector<int>> adj;  // adjacency list of graph
vector<vector<int>> adjm; // for topological sort
vector<bool> visited;
vector<int> ans;
vector<int> dis;

#define INF -9999

void dfs1(int v)
{
    visited[v] = true;
    for (int u : adjm[v])
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

void print()
{
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

void BellmanFord1(int V, int E, int src)
{
    // Initialize distance of all vertices as infinite.
    dis.resize(V + 1);
    dis.assign(dis.size(), INF);

    // initialize distance of source as 0
    dis[src] = 0;

    for (auto s : ans)
    {

        if (dis[s] != INF)
        {
            for (int v = 0; v <= V; v++)
            {
                if (adj[s][v] && adj[s][v] != INF)
                    if (dis[s] + adj[s][v] > dis[v])
                    {
                        dis[v] = dis[s] + adj[s][v];
                    }
            }
        }
    }
   
    /* for (auto s : ans)
    {
        int x = s;
        int y = adj[s][0];
        int weight = adj[s][1];
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl;
    } */

    cout << "\nVertex \t\tCost" << endl;
    for (auto s : ans)
        cout << s << "\t\t" << dis[s] << endl;
}

int main()
{
    int V = 0;   // Number of vertices.
    int E = 0;   // Number of edges.
    int src = 0; // Beginning of search.
    cin >> V >> E >> src;
    adj.resize(V + 1);
    adjm.resize(V + 1);
    visited.resize(V + 1);

    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            adj[i].push_back(INF);
        }
        adj[i][i] = 0;
    }

    int u, v, w;
    vector<int> vertices;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adjm[u].push_back(v);
        int u1 = u;
        int v1 = v;
        adj[u][v] = w;

        if (std::find(vertices.begin(), vertices.end(), u1) == vertices.end())
        {
            vertices.push_back(u1);
        }
        if (std::find(vertices.begin(), vertices.end(), v1) == vertices.end())
        {
            vertices.push_back(v1);
        }
    }

    sort(vertices.begin(), vertices.end());

    topological_sort(vertices);
    BellmanFord1(V, E, ans[0]);
    print();

    return 0;
}