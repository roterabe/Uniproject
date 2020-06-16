
// CPP program to print all paths of source to
// destination in given graph
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> path;
vector<vector<int>> q;
vector<vector<int>> g;
vector<int> p;
int cnt = 0;

// utility function for printing
// the found path in graph
void printpath(vector<int> &path)
{
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int> &path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int>> g, int src, int v, int e)
{
    // create a queue which stores
    // the paths
    cnt++;
    vector<int> nuance;
    if (!visited[src])
    {
        visited[src] = true;
        path.push_back(src);
    }

    for (int i = 0; i < g[src].size(); i++)
    {
        if (!visited[g[src][i]])
        {
            visited[g[src][i]] = true;
            path.push_back(g[src][i]);
        }
    }

    for (int i = cnt; i < path.size(); i++)
    {
        p.push_back(path[i-1]);
        findpaths(g, path[cnt], v, e);
        q.push_back(path);
    }

    for (auto qe : q)
    printpath(qe);

}

// driver program
int main()
{ // number of vertices
    int n, e, src;
    cin >> n >> e >> src;
    g.resize(n + 1);
    visited.resize(n + 1);
    visited.assign(n + 1, false);
    int v, u;

    for (int i = 0; i < e; i++)
    {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    // function for finding the paths
    findpaths(g, src, n, e);

    return 0;
}
