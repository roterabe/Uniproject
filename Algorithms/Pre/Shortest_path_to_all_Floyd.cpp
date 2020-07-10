#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<long long int>> G;

void floyd(int V){
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (G[i][k] + G[k][j] < G[i][j]){
                    G[i][j] = G[i][k] + G[k][j];
                }
}

int main()
{
    int V,E;
    cin>>V>>E;
    G.resize(V);

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            G[i].push_back(INF);
        }
        G[i][i] = 0;
    }
    
    int u,v,w;
    for(int m=0; m<E; m++){
        cin>>u>>v>>w;
        G[--u][--v] = w;
        G[v][u] = w;
    }

    floyd(V);

    int sum = 0, temp, vertex;
    for(int i=0; i<V; i++){
        temp=0;
        for(int j=0; j<V; j++){
            temp+= G[i][j];
        }
        if(i==0){ 
            sum = temp;
            vertex = i+1;
        }
        else if(temp<sum) {
            sum = temp;
            vertex = i+1;
        }
    }

    cout<<"vertex: "<<vertex<<endl;
}
