#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    // base case
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return ;
    }

    // pick up element
    if(target >= arr[ind]){
        ds.push_back(arr[ind]);
        findCombination(ind, target-arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(ind+1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target){
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