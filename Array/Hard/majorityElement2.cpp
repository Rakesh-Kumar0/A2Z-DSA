#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute force approch
// vector<int> majorityElement(vector<int> &arr, int n){
//     vector<int> list;
//     for(int i=0; i<n; i++){
//         if(list.size() == 0 || list[0] != arr[i]){
//             int cnt = 0;
//             for(int j=0; j<n; j++){
//                 if(arr[i] == arr[j]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/3){
//                 list.push_back(arr[i]);
//             }
//         }
//         if(list.size() == 2) break;
//     }
//     return list;
// }

// better approch

vector<int> majorityElement(vector<int> &arr, int n){
    vector<int> list;
    map<int, int> mpp;
    int mini = int(n/3) +1;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){
            list.push_back(arr[i]);
        }
        if(list.size() == 2) break;
    }
    return list;
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
    vector<int> result = majorityElement(arr, n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}