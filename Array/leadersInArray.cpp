#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// brute force approch
// vector<int> leaderInArray(vector<int> &arr, int n){
//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         int leader = true;
//         for(int j=i+1; j<n; j++){
//             if(arr[j] > arr[i]){
//                 leader = false;
//                 break;
//             }
//         }
//         if(leader == true)  ans.push_back(arr[i]);
//     }
//     return ans;
// }

// Optimal approch
vector<int> leaderInArray(vector<int> & arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
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

    vector<int> result = leaderInArray(arr, n);
    for(auto it : result){
        cout<<it <<" ";
    }
    return 0;
}