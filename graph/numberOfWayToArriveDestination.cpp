#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

int countPaths(int n, vector<vector<pair<int,int>>> &adjlist){
    vector<int> dist(n,1e9);
    vector<int> ways(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    int mod = (int)(1e9+7);
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adjlist[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            // this is first time i am coming with this shor distance
            if(dis+edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dis+edgeWt, adjNode});
                ways[adjNode] = ways[node];
            }
            // arriving another time with previous short path
            else if(dis + edgeWt == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1] % mod;
}
int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }
    int result = countPaths(n, adjlist);
    cout<<result;
    return 0;
}