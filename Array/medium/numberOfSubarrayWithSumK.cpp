#include<iostream>
#include<vector>
#include<map>
using namespace std;

//brute force approch
// int numberOfSubarrayWithSumK(vector<int> &arr, int n, int k){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum +=arr[k];
//             }
//             if(sum == k){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

//better approch

// int numberOfSubarrayWithSumK(vector<int> &arr, int n, int k){
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum +=arr[j];
//             if(sum == k){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// optimal approch

int numberOfSubarrayWithSumK(vector<int> &arr, int n, int k){
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        preSum +=arr[i];
        int remove = preSum - k;
        cnt = cnt + mpp[remove];
        mpp[preSum] +=1;
    }
    return cnt;
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
    int k;
    cout<<"Enter target : ";
    cin>>k;
    int result = numberOfSubarrayWithSumK(arr, n, k);
    cout<<result;
    return 0;
}