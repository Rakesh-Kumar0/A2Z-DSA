#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;

// brute force

// void findCombination(int ind, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds){
//     // base case
//     if(ind == arr.size()){
//         if(target == 0){
//             ans.insert(ds);
//         }
//         return ;
//     }

//     // pick up element
//     if(target >= arr[ind]){
//         ds.push_back(arr[ind]);
//         findCombination(ind+1, target-arr[ind], arr, ans, ds);
//         ds.pop_back();
//     }
//     findCombination(ind+1, target, arr, ans, ds);
// }

// set<vector<int>> combinationSum(vector<int> &arr, int target){
//     set<vector<int>> ans;
//     vector<int> ds;
//     findCombination(0, target, arr, ans, ds);
//     return ans;
// }

 // optimal approch
void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    //base case
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i=idx; i<arr.size(); i++){
        if(i>idx && arr[i] == arr[i-1]) continue;
        if(target  < arr[i]) break;
        ds.push_back(arr[i]);
        findCombination(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, arr, ans, ds);
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
    int target;
    cout<<"Enter target value : ";
    cin>>target;
    vector<vector<int>> result = combinationSum(arr, target);
    for(auto row : result){
        for(auto it : row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}