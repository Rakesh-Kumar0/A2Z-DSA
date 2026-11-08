#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    for(auto it : adjlist[node]){
        if(!vis[it]){
            if(dfs(it, adjlist, vis, pathVis,check) == true){
                check[node] = 0;
                return true;
            } 
        }
        else if(pathVis[it]){
            check[node] = 0;
            return true;
        } 
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
// function to safe nodes in directed graph
vector<int> eventualSafeNode(int v, vector<vector<int>> &adjlist){
    vector<int> vis(v+1,0);
    vector<int> pathVis(v+1,0);
    // this is for safe node check
    vector<int> check(v+1, 0);
    vector<int> safeNode;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, adjlist, vis, pathVis, check);
        }
    }
    for(int i=0; i<v; i++){
        if(check[i] == 1) safeNode.push_back(i);
    }
    return safeNode;
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
    vector<int> result = eventualSafeNode(n, adjlist);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}