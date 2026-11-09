#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> isPossible(int N, vector<pair<int,int>> prerequisites){
    // convert matrix to adjlist
    vector<vector<int>> adjlist(N);
    for(auto it : prerequisites){
        adjlist[it.second].push_back(it.first);
    }

    vector<int> indegree(N);
    for(int i=0; i<N; i++){
        for(auto it : adjlist[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adjlist[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == N) return topo;
    return {};
}
int main(){
    int numCourses;
    cout<<"Enter Number of courese : ";
    cin>>numCourses;
    int m;
    cout << "Enter number of prerequisite pairs: ";
    cin >> m;
    vector<pair<int,int>> prerequisites;
    cout << "Enter prerequisite pairs: ";
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        prerequisites.push_back({u,v});
    }
    vector<int> result = isPossible(numCourses, prerequisites);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}