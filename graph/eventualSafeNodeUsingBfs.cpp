#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function to safe nodes in directed graph
vector<int> eventualSafeNode(int v, vector<vector<int>> &adjlist){
    // reverse the edges
    vector<vector<int>> adjrev(v);
    vector<int> indegree(v);
    for(int i=0; i<v; i++){
        for(auto it : adjlist[i]){
            adjrev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNode;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNode.push_back(node);
        for(auto it : adjrev[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}
int main(){
    int n,m;
    cout<<"Enter number of nodes and number of edges : ";
    cin>>n>>m;
    vector<vector<int>> adjlist(n);
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