#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

int cheapestFlight(int n, vector<vector<pair<int,int>>> &adjlist, int src, int dest, int k){
    vector<int> dist(n,1e9);
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    dist[src] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if(stops > k) continue;
        for(auto iter : adjlist[node]){
            int adjNode = iter.first;
            int edgeCost = iter.second;
            if(cost + edgeCost < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + edgeCost;
                q.push({stops+1,{adjNode,cost+edgeCost}});
            }
        }
    }
    if(dist[dest] == 1e9) return -1;
    return dist[dest];
}
int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adjlist[u].push_back({v,cost});
    }
    int src,dest,stop;
    cout<<"Enter source : ";
    cin>>src;
    cout<<"Enter destination : ";
    cin>>dest;
    cout<<"Enter no. of stops : ";
    cin>>stop;
    int result = cheapestFlight(n, adjlist, src, dest,stop);
    cout<<result;
    return 0;
}