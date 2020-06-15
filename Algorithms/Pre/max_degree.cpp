#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> a; // Vector with limit of 100 points.
vector<int> vertices;
vector<int> mins;
int minimal = INT_MAX;
int maximal = 0;

int main()
{
    int n = 0; // Size.
    int r = 0; //Edges.
    cin >> n >> r;
    a.resize(n+1);
    visited.resize(n+1);

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
        a[c1].push_back(c);
        if (std::find(vertices.begin(), vertices.end(), c) == vertices.end())
        {
            vertices.push_back(c);
        }
        if (std::find(vertices.begin(), vertices.end(), c1) == vertices.end())
        {
            vertices.push_back(c1);
        }

        r1 -= 1;
    }

    for (int v = 0; v < n; v++)
    {
        sort(a[v].begin(), a[v].end());
    }
    
    for (auto v : vertices){
        if (maximal < a[v].size())
            maximal = a[v].size();
        if (minimal > a[v].size())
            minimal = a[v].size();
    }
        
    cout << maximal << " " << minimal;
}