#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// function to check the given graph is bipartite

bool isBipartite(int V, vector<vector<int>> &adjlist){
    queue<int> q;
    q.push(1);
    vector<int> color(V,-1);
    color[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adjlist[node]){
            // if the adjacent node is not yet colored give them opposite color of node
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            // is the adlacent node having the same color someone did color it on some other path
            else if(color[it] == color[node]){
                return false;
            }
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