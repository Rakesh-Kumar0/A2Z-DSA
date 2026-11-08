#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

// function to return list containing vertices in topologocal order
vector<int> topoSort(int v, vector<vector<int>> &adjlist){
    vector<int> indegree(v+1);
    for(int i=0; i<v; i++){
        for(auto it : adjlist[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort so please remove it from the indegree 
        for(auto it : adjlist[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
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