#include <iostream>
#include <vector>
#include <stack>
#define INF 1000000000
using namespace std;

vector<vector<long long int>> G; //Adjacency list.
vector<vector<long long int>> P; //Parent node.

void floyd(int V)
{
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (G[k][j] != INF && G[i][k] != INF && G[i][k] + G[k][j] < G[i][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                    P[i][j] = k;
                }
}

int main()
{
    int V, E;
    cin >> V >> E;
    G.resize(V);
    P.resize(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            G[i].push_back(INF);
            P[i].push_back(-1);
        }
        G[i][i] = 0;
        P[i][i] = 0;
    }

    int u, v, w;
    for (int m = 0; m < E; m++)
    {
        cin >> u >> v >> w;
        G[--u][--v] = w;
        P[u][v] = u;
    }

    floyd(V);

    return 0;
}
