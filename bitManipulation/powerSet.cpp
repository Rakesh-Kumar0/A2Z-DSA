#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> powerSet(vector<int> &arr){
    int subset = 1<<arr.size();
    vector<vector<int>> ans;
    for(int num=0; num<subset; num++){
        vector<int> list;
        for(int i=0; i<arr.size(); i++){
            if(num & 1<<i){
                list.push_back(arr[i]);
            }
        }
        ans.push_back(list);
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
    vector<vector<int>> result = powerSet(arr);
   for(auto row : result){
        for(auto it : row){
            cout<<it <<" ";
        }
        cout<<endl;
   }
    return 0;
}