
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int res = 0;

void BellmanFord1(vector<vector<int>> graph, vector<int> vertices, int V, int E,
                  int src)
{
    // Initialize distance of all vertices as infinite.
    vector<int> dis(MAX);
    dis.assign(dis.size(), MAX);

    // initialize distance of source as 0
    dis[src] = 0;

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

    // check for negative-weight cycles.
    // The above step guarantees shortest
    // distances if graph doesn't contain
    // negative weight cycle.  If we get a
    // shorter path, then there is a cycle.
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl;
    }

    int max = 0;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        if (max < dis[vertices[i]] && dis[vertices[i]] != MAX)
            max = dis[vertices[i]];
    }
    if (res < max)
        res = max;

    /* cout << "Vertex \t\tDistance from Source" << endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << "\t\t" << dis[vertices[i]] << endl;
    } */
}

// Driver program to test above functions
int main()
{
    int V = 0; // Number of vertices in graph
    int E = 0; // Number of edges in graph
    cin >> V >> E;
    vector<vector<int>> g;
    vector<int> vertices;

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        g.push_back({u, v, 1});
        if (std::find(vertices.begin(), vertices.end(), u) == vertices.end())
        {
            vertices.push_back(u);
        }
        if (std::find(vertices.begin(), vertices.end(), v) == vertices.end())
        {
            vertices.push_back(v);
        }
    }

    for (auto ve : vertices)
        BellmanFord1(g, vertices, V, E, ve);
    cout << res << endl;
    return 0;
}
