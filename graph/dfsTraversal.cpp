#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function of dfs traversal
void dfs(int node, vector<vector<int>> &adjlist,vector<int> &vis, vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    // traverse all its neighbour
    for(auto it : adjlist[node]){
        if(!vis[it]){
            dfs(it, adjlist, vis, ls);
        }
    }
}
// function to return a list containing dfs traversal of the graph
vector<int> dfsOfGraph(int v, vector<vector<int>> &adjlist){
    vector<int> vis(v,0);
    int start = 1;
    vector<int> ls;
   dfs(start, adjlist, vis, ls);
   return ls;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjlist(n+1);
    // vector<int> vis(n,0);
    for(int i=0;i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> result = dfsOfGraph(n,adjlist);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}