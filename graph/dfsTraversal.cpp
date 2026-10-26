#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 0- base indexing graph
vector<int> bfsTraversal(int v, vector<vector<int>> &adjlist){
    vector<int> vis(v,0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adjlist[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjlist(n+1);
    vector<int> vis(n,0);
    for(int i=0;i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> result = bfsTraversal(n,adjlist);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}