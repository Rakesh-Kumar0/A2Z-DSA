#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// for multiple components
bool dfs(int start, int col, vector<int> &color, vector<vector<int>> &adjlist){
    color[start] = col;
    for(auto it : adjlist[start]){
        if(color[it] == -1){
            if(dfs(it, !col, color, adjlist) == false) return false ;
        }
        else if(color[it] == col) return false;
    }
    return true;
}
bool isBipartite(int v, vector<vector<int>> &adjlist){
    vector<int> color(v,-1);
    for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(dfs(i, 0, color, adjlist) == false) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cout<<"Enter numner of nodes and number of edges : ";
    cin>>n>>m;
    vector<vector<int>> adjlist(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bool result = isBipartite(n,adjlist);
    cout<<result;
    return 0;
}