
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

// The main function that finds shortest
// distances from src to all other vertices
// using Bellman-Ford algorithm. The function
// also detects negative weight cycle
// The row graph[i] represents i-th edge with
// three values u, v and w.
void BellmanFord(int graph[][3], int V, int E,
                 int src)
{
    // Initialize distance of all vertices as infinite.
    vector<int> dis(MAX);
    dis.assign(dis.size(), INT_MAX);

    // initialize distance of source as 0
    dis[src] = 0;

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] <
                dis[graph[j][1]])
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];
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

    cout << "Vertex \t\tDistance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}

void BellmanFord1(vector<vector<int>> graph, vector<int> vertices, int V, int E,
                  int src)
{
    // Initialize distance of all vertices as infinite.
    vector<int> dis(MAX);
    dis.assign(dis.size(), INT_MAX);
    vector<vector<int>> data(MAX);

    // initialize distance of source as 0
    dis[src] = 0;
    data[src].push_back(0);

    // Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] <
                dis[graph[j][1]])
            {
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];

                data[graph[j][0]].push_back(graph[j][1]);
                data[graph[j][1]].push_back(graph[j][0]);
                /* if (data[graph[j][0]].size() == 0)
                    data[graph[j][0]].push_back(graph[j][1]); */
            }
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

    cout << "Vertex \t\tDistance from Source" << endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << "\t\t" << dis[vertices[i]] << endl;
    }

    for (int i = 0; i < vertices.size(); i++)
    {
        int min = INT_MAX;
        int push = 0;
        for (int j = 0; j < data[vertices[i]].size(); j++)
        {
            if (vertices[i] == data[vertices[i]][j])
                continue;
            int temp = dis[data[vertices[i]][j]];
            if (temp < min)
            {
                min = temp;
                push = data[vertices[i]][j];
            }
        }
        data[vertices[i]].clear();
        data[vertices[i]].push_back(push);
    }

    cout << "\nVertex \t\tCost" << endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << "\t\t" << data[vertices[i]][0] << endl;
    }
}

// Driver program to test above functions
int main()
{
    int V = 0; // Number of vertices in graph
    int E = 0; // Number of edges in graph
    cin >> V >> E;
    vector<vector<int>> g;
    vector<int> vertices;

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
        if (std::find(vertices.begin(), vertices.end(), u) == vertices.end())
        {
            vertices.push_back(u);
        }
        if (std::find(vertices.begin(), vertices.end(), v) == vertices.end())
        {
            vertices.push_back(v);
        }
    }

    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    //int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    //BellmanFord(graph, 5, 8, 0);
    BellmanFord1(g, vertices, V, E, 1);
    return 0;
}
