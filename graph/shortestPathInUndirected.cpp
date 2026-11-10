#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> shortestPath(int n, int m, int src,  vector<vector<int>> &adjlist){
    queue<int> q;
    vector<int> dist(n,1e9);
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adjlist[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1+ dist[node];
                q.push(it);
            }
        }
    }
    vector<int> ans(n,-1);
    for(int i=0; i<m; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<int>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int src;
    cout<<"Enter source node : ";
    cin>>src;
    vector<int> result = shortestPath(n,m,src,adjlist);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}
