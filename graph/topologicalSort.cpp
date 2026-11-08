#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// function to find topological ordering

void dfs(int node, vector<int> &vis, vector<vector<int>> &adjlist, stack<int> &st){
    vis[node] = 1;
    for(auto it : adjlist[node]){
        if(!vis[it]){
            dfs(it,vis,adjlist,st);
        }
    }
    st.push(node);
}

// function of component
vector<int> topoSort(int v, vector<vector<int>> &adjlist){
    vector<int> vis(v+1, 0);
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, adjlist, st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Enter number of nodes and number of edges of directed acyclic graph : ";
    cin>>n>>m;
    vector<vector<int>> adjlist(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    vector<int> result = topoSort(n, adjlist);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}