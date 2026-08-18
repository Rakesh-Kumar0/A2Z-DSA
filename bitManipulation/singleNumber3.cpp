#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// brute force
vector<int> singleElement(vector<int> &arr){
    map<int, int> mpp;
    for(int i=0; i<arr.size(); i++){
        mpp[arr[i]]++;
    }
    vector<int> ans;
    for(auto it : mpp){
        if(it.second == 1) ans.push_back(it.first);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> result = singleElement(arr);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}