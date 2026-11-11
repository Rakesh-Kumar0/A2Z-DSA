#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

// function for dijkstra's algorithm
vector<int> dijkstra(int v, vector<vector<vector<int>>> &adjlist, int src){
    vector<int> dist(v,1e9);
    set<pair<int,int>> st;
    dist[src] = 0;
    st.insert({0,src});
    while(!st.empty()){
        auto it = *(st.begin()); // it will give top element, without * it will give address
        int dis = it.first;
        int node = it.second;
        st.erase(it);
        for(auto it : adjlist[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis + edgeWeight < dist[adjNode]){
                // if someone already visit that node before then erase it
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int n,m;
    cout<<"Enter no. of nodes and no. of edges : ";
    cin>>n>>m;
    vector<vector<vector<int>>> adjlist(n);
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }
    int src;
    cout<<"Enter source node : ";
    cin>>src;
    vector<int> result = dijkstra(n,adjlist,src);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}
