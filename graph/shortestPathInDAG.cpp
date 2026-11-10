#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

// function of dfs traversal
void dfs(int node, vector<int> &vis, vector<vector<pair<int,int>>> &adjlist, stack<int> &st){
    vis[node] = 1;
    for(auto it : adjlist[node]){
        if(!vis[it.first]){
            dfs(it.first,vis,adjlist,st);
        }
    }
    st.push(node);
}
// function to find shortest path
vector<int> shortestPath(int n, int m, vector<vector<pair<int,int>>> & adjlist){
    // step:1->topo sort
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,vis,adjlist,st);
        }
    }
    //step:2->find path
    vector<int> dist(n,1e9);
    dist[0] = 0; // source distance
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adjlist[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] != 1e9 && dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
    }
    vector<int> result = shortestPath(n,m,adjlist);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}