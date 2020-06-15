#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> a;
vector<int> p;
bool ch = false;

void dfs(int v)
{
    visited[v] = true;
    
    for (int i = 0; i < a[v].size(); i++)
    {
        if (std::find(p.begin(), p.end(), a[v][i]) != p.end()){
            ch = true;
        }
        if (!visited[a[v][i]]){
            p.push_back(v);
            dfs(a[v][i]);
        }
    }
    p.pop_back();
}

int main()
{
    int n = 0; // Number of corners.
    int r = 0; // Number of roads.
    cin >> n >> r;
    a.resize(n+1);
    visited.resize(n+1);
    
        
    vector<int> vertices;
    
    int c = 1;
    int c1 = 1;

    int r1 = r;

    while (c != 0 || c1 != 0)
    {
        if (r1 == 0)
        {
            break;
        }
        cin >> c >> c1;
        a[c].push_back(c1);
        if (std::find(vertices.begin(), vertices.end(), c) == vertices.end())
        {
            vertices.push_back(c);
        }

        r1 -= 1;
    }

    for (int v = 0; v < n; v++)
    {
        sort(a[v].begin(), a[v].end());
    }
    
    for (auto v : vertices){
        p.clear();
        visited.assign(n+1, false);
        dfs(v);
    }
    
    if (ch == true)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}