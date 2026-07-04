#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// brute force approch
vector<vector<int>> mergeOverlappingSubinterval(vector<vector<int>> &interval, int n){
    sort(interval.begin(), interval.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        int start = interval[i][0];
        int end = interval[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;
        for(int j=i+1; j<n; j++){
            if(interval[j][0] <= end){
                end = max(end, interval[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter number of interval : ";
    cin>>n;
    vector<vector<int>> interval;
    cout<<"Enter elemente of an interval : ";
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        interval.push_back({start, end});
    }
    vector<vector<int>> result = mergeOverlappingSubinterval(interval, n);
    for(auto it : result){
        cout<<"{" << it[0] << it[1] << "}"<<endl;
    }
    return 0;
}