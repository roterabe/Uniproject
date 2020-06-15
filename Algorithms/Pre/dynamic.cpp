#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX 1000

void dynamic(vector<vector<int>> g, int size, int edges, int source)
{
    vector<int> dis(MAX);
    dis.assign(dis.size(), INT_MAX);
    dis[source] = 0;
}

int main()
{
    vector<vector<int>> g;
    int size, edges, source;
    cin >> size >> edges >> source;

    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }

    return 0;
}