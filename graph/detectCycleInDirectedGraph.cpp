#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &vis, vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it : adjlist[node]){
        // when the node is not visited
        if(!vis[it]){
            if(dfs(it, adjlist, vis, pathVis) == true) return true;
        }
        //if the node has been previously visited but it has to be visited on same path
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
// function to detect cycle in directed graph
bool isCycle(int v, vector<vector<int>> &adjlist){
    vector<int> vis(v+1,0);
    vector<int> pathVis(v+1,0);
    for(int i=0 ;i<v; i++){
        if(!vis[i]){
            if(dfs(i, adjlist, vis, pathVis) == true) return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cout<<"Enter number of nodes and number of edges : ";
    cin>>n>>m;
    vector<vector<int>> adjlist(n+1);
    for(int i=0 ; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    bool result = isCycle(n, adjlist);
    cout<<result;
    return 0;
}