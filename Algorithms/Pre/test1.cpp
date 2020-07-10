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
int cnt = 0;

#define INF 999999

void printSolution(int V);

void floydWarshall(int V)
{

    int i, j, k;
    dis.resize(V + 1);
    for (int i = 0; i < dis.size(); i++)
        dis[i].resize(V + 1);

    for (i = 0; i < V + 1; i++)
        for (j = 0; j < V + 1; j++)
        {
            dis[i][j] = G[i][j];
            if (G[i][j] != INF && i != j)
                iaPath[i][j] = i;

            else
                iaPath[i][j] = -1;
        }

    for (k = 0; k < V + 1; k++)
    {

        for (i = 0; i < V + 1; i++)
        {

            for (j = 0; j < V + 1; j++)
            {

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
    //printSolution(V);
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

void getNumberEdges(int from, int to)
{
    stack<int> S;
    int src;

    S.push(to);

    src = iaPath[from][to]; //Get parent or from vertex ID.

    while (1)
    {
        if (src == -1)
        { //Check path exists.
            cout << "There is no path\n";
            return;
        }
        S.push(src);

        if (from == src)
            break; //Check if from vertex and source vertex are the same. Is so, touchdown!!!
        src = iaPath[from][src];
    }

    //cout << iSrc << "==>" << endl;
    while (!S.empty())
    {
        cnt += 1;
        S.pop();
    }
    cnt -= 1;
}
// driver program to test above function
int main()
{
    int V, E;
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
    int from, to;
    cin >> from >> to;

    // Print the solution

    floydWarshall(V);

    getNumberEdges(from, to);
    cout << cnt << endl;

    return 0;
}