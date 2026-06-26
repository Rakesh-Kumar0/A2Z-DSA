#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute Force approch

// int majorityElement(vector<int> &arr, int n){
//     for(int i=0; i<n; i++){
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(arr[i] == arr[j]){
//                 cnt++;
//             }
//         }
//         if(cnt > (n/2)) return arr[i];
//     }
//     return -1;
// }

// Better Approch

// int majorityElement(vector<int> &arr, int n){
//     map<int, int> mpp;
//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second > (n / 2)){
//             return it.first;
//         }
//     }
//     return -1;
// }

// Optimal Approch using moore's algorithm

int majorityElement(vector<int> &arr, int n){
    int element;
    int cnt =0;
    for(int i=0; i<n; i++){
        if(cnt == 0){
            cnt++;
            element = arr[i];
        }
        else if(arr[i] == element){
            cnt++;
        }
        else cnt--;
    }
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == element){
            cnt1++;
        }
    }
    if(cnt1 > n/2) return element;
    return -1;
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
    int result = majorityElement(arr, n);
    cout<<result;
    return 0;
}