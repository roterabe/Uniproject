#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int stage = 0;

void printLevels(vector<vector<int>> graph, int V, int x)
{

    vector<int> level(V + 1);
    vector<bool> marked(V + 1);

    queue<int> que;

    que.push(x);

    level[x] = 0;

    marked[x] = true;

    while (!que.empty())
    {

        x = que.front();

        que.pop();

        for (int i = 0; i < graph[x].size(); i++)
        {
            int b = graph[x][i];

            if (!marked[b])
            {

                que.push(b);

                level[b] = level[x] + 1;

                marked[b] = true;
            }
        }
    }

    int temp = level[V];
    for (int i = 0; i < V + 1; i++)
        if (level[i] == temp && level[i] > 0)
        {
            cnt++;
        }
}

int main()
{

    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    vector<int> vertices;

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        if (find(vertices.begin(), vertices.end(), u) == vertices.end())
            vertices.push_back(u);
        if (find(vertices.begin(), vertices.end(), v) == vertices.end())
            vertices.push_back(v);
    }

    for (auto e : vertices)
    {
        cnt = 0;
        printLevels(graph, V, e);
        if (stage < cnt)
        {
            stage = cnt;
        }
    }
    cout << stage << endl;
    return 0;
}
