// C Program for Floyd Warshall Algorithm
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> G; //Adjacency list.
vector<vector<int>> dis;
vector<vector<int>> iaPath;

#define INF 999999

// A function to print the solution matrix
void printSolution(int V);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(int V)
{
    /* dist[][] will be the output matrix that will finally have the shortest
distances between every pair of vertices */
    int i, j, k;
    dis.resize(V + 1);
    for (int i = 0; i < dis.size(); i++)
        dis[i].resize(V + 1);

    /* Initialize the solution matrix same as input graph matrix. Or
we can say the initial values of shortest distances are based
on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V + 1; i++)
        for (j = 0; j < V + 1; j++)
        {
            dis[i][j] = G[i][j];
            if (G[i][j] != INF && i != j)
                iaPath[i][j] = i; //Indicates the source vertex.
            //iPath[2][3] = 2 means source vertex is 2 and destination vertex is 3.
            else
                iaPath[i][j] = -1; //Indicates there is no path.
        }
    /* Add all vertices one by one to the set of intermediate vertices.
---> Before start of an iteration, we have shortest distances between all
pairs of vertices such that the shortest distances consider only the
vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
----> After the end of an iteration, vertex no. k is added to the set of
intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V + 1; k++) //Why this loop is needed? What purpose does it serve?
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V + 1; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V + 1; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    iaPath[i][j] = iaPath[k][j];
                }
            }
        }
    }

    //Detect if negative cycle exists.
    for (i = 0; i < V + 1; i++)
        for (j = 0; j < V + 1; j++)
            if (i == j && dis[i][j] != 0)
                cout << "Negative cycle detected!\n"
                     << endl;

    // Print the shortest distance matrix
    printSolution(V);
}

/* A utility function to print solution */
void printSolution(int V)
{
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            if (dis[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dis[i][j]);
        }
        printf("\n");
    }
}

/* A utility function to print solution */
void printPaths(int V)
{
    printf("The following matrix shows the paths \n");

    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            printf("%7d", iaPath[i][j]);
        }
        printf("\n");
    }
}

void printExactPaths(int iSrc, int iDest)
{
    stack<int> S;
    int iFrom;

    S.push(iDest);

    iFrom = iaPath[iSrc][iDest]; //Get parent or from vertex ID.

    while (1)
    {
        if (iFrom == -1)
        { //Check path exists.
            cout << "There is no path\n";
            return;
        }
        S.push(iFrom);

        if (iSrc == iFrom)
            break; //Check if from vertex and source vertex are the same. Is so, touchdown!!!
        iFrom = iaPath[iSrc][iFrom];
    }

    //cout << iSrc << "==>" << endl;
    while (!S.empty())
    {
        cout << S.top() << "==>";
        S.pop();
    }
    cout << endl;
}
// driver program to test above function
int main()
{
    int V, E, src;
    cin >> V >> E;
    G.resize(V + 1);
    iaPath.resize(V + 1);
    for (int i = 0; i < V + 1; i++)
        iaPath[i].resize(V + 1);

    for (int i = 0; i < V + 1; i++)
    {
        for (int j = 0; j < V + 1; j++)
        {
            G[i].push_back(INF);
        }
        G[i][i] = 0;
    }

    int u, v, w;
    for (int m = 0; m < E; m++)
    {
        cin >> u >> v >> w;
        G[u][v] = w;
    }

    // Print the solution

    floydWarshall(V);

    printExactPaths(1, 9);
    //printExactPaths(2, 1);
    return 0;
}