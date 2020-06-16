// CPP program to print all paths of source to
// destination in given graph
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> res;
// utility function for printing
// the found path in graph
void printpath(vector<int> &path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
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
void findpaths(vector<vector<int>> &g, int src,
               int dst, int v)
{
    // create a queue which stores
    // the paths
    queue<vector<int>> q;

    // path vector to store the current path
    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        // if last vertex is the desired destination
        // then print the path
        if (last == dst)
        {
            printpath(path);
            res.push_back(path);
        }
        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        for (int i = 0; i < g[last].size(); i++)
        {
            if (isNotVisited(g[last][i], path))
            {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

// driver program
int main()
{ // number of vertices
    int n, e, src;
    cin >> n >> e >> src;
    g.resize(n + 1);
    vector<int> vertices;
    int v, u;

    for (int i = 0; i < e; i++)
    {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
        if (std::find(vertices.begin(), vertices.end(), v) == vertices.end())
            vertices.push_back(v);
        if (std::find(vertices.begin(), vertices.end(), u) == vertices.end())
            vertices.push_back(u);
    }

    int dst = n;
    cout << "path from src " << src
         << " to dst " << dst << " are \n";

    // function for finding the paths
    for (auto v : vertices)
        findpaths(g, src, v, n);

    return 0;
}
