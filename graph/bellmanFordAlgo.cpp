#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>> & edges, int src){
    vector<int> dist(n,1e8);
    for(int i=0; i<n-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth iteration to check negative cycle
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}
int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    int src;
    cout<<"Enter source : ";
    cin>>src;
    vector<int> result = bellmanFord(n, edges,src);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}