#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// function to find spanning tree
int spanningTree(int v, vector<vector<pair<int,int>>> &adjlist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(v,0);
    vector<pair<int,int>> mst;
    // {wt,node}
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node] == 1) continue;
        // only mark as visited when we add it in mst
        vis[node] = 1;
        sum += wt;
        for(auto it : adjlist[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(!vis[adjNode]){
                pq.push({edgeWt, adjNode});
            }
        }

    }
    return sum;

}

int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjList(n);
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
    }
    int result = spanningTree(n,adjList);
    cout<<result;
    return 0;
}