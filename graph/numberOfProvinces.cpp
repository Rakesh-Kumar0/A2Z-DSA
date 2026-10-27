#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// function to dfs traversal
void dfs(int node, vector<vector<int>> &adjlist, vector<int> &vis){
    vis[node] = 1;
    for(auto it : adjlist[node]){
        if(!vis[it]){
            dfs(it, adjlist, vis);
        }
    }
}

// function to count number of proviences
int numberOfProviences(vector<vector<int>> & adjmat, int n){
    vector<vector<int>> adjlist(n+1);
    // to change adjacency matrix to list
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(adjmat[i][j] == 1 && i != j){
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }

    vector<int> vis(n+1, 0);
    int cnt = 0;
    for(int i=1; i<n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjlist, vis);
        }
    }

    return cnt;
}
int main(){
    // take number of vertices and number of edges as input
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjmat(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }
    int result = numberOfProviences(adjmat, n);
    cout<<result;
    return 0;
}