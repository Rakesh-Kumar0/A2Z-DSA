#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adjlist[n+1];
    //vector<vector<int>> adjlist(n + 1); same as above
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    // Print adjacency list
    for(int i=0; i<=n; i++){
        cout<<i <<"->";
        for(int neighbour : adjlist[i]){
            cout<<neighbour <<" ";
        }
        cout<<endl;
    }
    return 0;
}