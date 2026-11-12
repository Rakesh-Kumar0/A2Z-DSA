#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

// function to find shortest path
vector<int> shortestPath(int n, int m, vector<vector<pair<int, int>>> &adjlist){
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    vector<int> dist(n+1,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        for(auto it : adjlist[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dis + edgeWt, adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);// pushing src node
    reverse(path.begin(), path.end());
    return path;

}
int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<pair<int, int>>> adjlist(n+1); // n+1 because it is 1 based graph
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }
    vector<int> result = shortestPath(n,m,adjlist);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}