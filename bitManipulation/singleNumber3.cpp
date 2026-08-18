#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// brute force
// vector<int> singleElement(vector<int> &arr){
//     map<int, int> mpp;
//     for(int i=0; i<arr.size(); i++){
//         mpp[arr[i]]++;
//     }
//     vector<int> ans;
//     for(auto it : mpp){
//         if(it.second == 1) ans.push_back(it.first);
//     }
//     return ans;
// }


// optimal using bucket concept
pair<int, int> singleElement(vector<int> &arr){
   long long xorr = 0;
   for(int i=0; i<arr.size(); i++){
    xorr = xorr ^ arr[i];
   }
   int rightmost = xorr &(xorr-1)^xorr;
   int bucket1 = 0;
   int bucket2 = 0;
   for(int i=0; i<arr.size(); i++){
        if(arr[i] & rightmost) bucket1 = bucket1 ^ arr[i];
        else bucket2 = bucket2 ^ arr[i];
   }
   return {bucket1, bucket2};
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
    pair<int, int> result = singleElement(arr);
    cout<<result.first <<" "<<result.second;
    return 0;
}