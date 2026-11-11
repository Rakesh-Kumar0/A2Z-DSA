#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// function for dijkstra's algorithm
vector<int> dijkstra(int v, vector<vector<vector<int>>> &adjlist, int src){
    vector<int> dist(v,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // min_heap
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adjlist[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<vector<int>>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }
    int src;
    cout<<"Enter source node : ";
    cin>>src;
    vector<int> result = dijkstra(n,adjlist,src);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}
