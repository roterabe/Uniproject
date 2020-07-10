#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<int>> iaPath;

void getShortestPath(int end, int endVertices[])
{
    /* if (endVertices[end] == 0)
        return;
    getShortestPath(endVertices[end], endVertices);
    cout << endVertices[end]; */
    for (int i = 0; i < end; i++)
        cout << endVertices[i] << " ";
}

void BellmanFord(int graph[][3], int V, int E, int src)
{
    int dis[V + 1];
    int endVertices[V + 1];
    int temp[V + 1][1];

    for (int i = 1; i <= V; i++)
    {
        dis[i] = INF;
        endVertices[i] = src;
    }

    dis[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
                endVertices[graph[j][1]] = graph[j][0];
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        temp[i][1] = dis[i];
    }

    /*  for(int i=1; i<=V; i++){
        cout<<i<<" "<<temp[i][1]<<endl;
    } */

    getShortestPath(V, endVertices);

    /* cout << "Vertex Distance from Source" << endl; 
    for (int i = 1; i <= V; i++) 
        cout << i << "\t\t" << dis[i] << endl; */
}

int main()
{
    int src, V, E;
    cin >> V >> E;
    int graph[E][3];

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }
    cin >> src;
    BellmanFord(graph, V, E, src);
    return 0;
}