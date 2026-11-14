#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int minimumMultiplication(vector<int> & multi, int start, int end){
    auto const mod = 100000;
    vector<int> dist(100000,1e9);
    queue<pair<int,int>> q;
    dist[start] = 0;
    q.push({start,0});
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for(auto it : multi){
            int num = (it * node) %mod;
            if(steps +1 < dist[num]){
                dist[num] = steps+1;
                if(num == end) return steps + 1;
                q.push({num, steps+1});
            }
        }
    }
    return -1;
}

int main(){
    int start,end;
    cout<<"Enter start and end : ";
    cin>>start>>end;
    int n;
    cout<<"Enter size of multi array : ";
    cin>>n;
    vector<int> multi(n);
    for(int i=0; i<n; i++){
        cin>>multi[i];
    } 
    int result = minimumMultiplication(multi, start, end);
    cout<<result;
    return 0;
}