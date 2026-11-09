#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

// function of topo sort
vector<int> topoSort(int v, vector<vector<int>> &adjlist){
    vector<int> indegree(v);
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

string findOrder(vector<string> dict, int N, int K){
    // first find the DAG->directed acylic graph here N->number of string and K-> number of letter(vertices) i.e a,b,c....
    vector<vector<int>> adjlist(K);
    for(int i=0; i<N-1; i++){ // only till N-1 because if we do N the i+1 does not exist
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());
        for(int ptr=0; ptr<len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adjlist[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // -1 to get a number 
                break;
            }
        }
    }
    vector<int> topo = topoSort(K, adjlist);
    string ans = "";
    for(auto it : topo){
        ans = ans + char(it + 'a'); // +a to get a alphabet not number
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of dictionary : ";
    cin>>n;
    vector<string> dict(n);
    for(int i=0; i<n; i++){
        cin>>dict[i];
    }
    int k;
    cout<<"Enter number of order(letter) : ";
    cin>>k;
    string result = findOrder(dict, n, k);
    cout<<result;
    return 0;
}