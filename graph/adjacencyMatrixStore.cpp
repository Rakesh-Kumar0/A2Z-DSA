#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // take input as no. of vertices and no. of edge
    int n, m;
    cin>>n >>m;

    // Create an adjacency matrix
    vector<vector<int>> adj((n+1), vector<int>(n+1));

    // Take input for all edges
    for(int i=0; i<m;i++){
        int u, v;
        cin>>u >>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0; i<=n;i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}