#include<iostream>
#include<vector>
using namespace std;

// Brute force approch

// int missingNumber(vector<int> &arr, int n){
//     for(int i=1; i<=n; i++){
//         int flag = 0;
//         for(int j=0; j<n-1; j++){
//             if(arr[j] == i){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0){
//             return i;
//         }
//     }
//       return 0;
// }


// Better approch

// int missingNumber(vector<int> & arr, int n){
//     vector<int> hash(n+1);
//     for(int i=0; i<n-1; i++){
//         hash[arr[i]] = 1;
//     }
//     for(int i=1; i<=n; i++){
//         if(hash[i] == 0) return i;
//     }
//     return 0;
// }


// Optimal approch

int missingNumber(vector<int> &arr, int n){
    int sumOfFirstNNumber = (n * (n + 1)) / 2;
    int newSum = 0;
    for(int i=0; i<n-1; i++){
        newSum += arr[i];
    }
    return sumOfFirstNNumber - newSum;
}

int main(){
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n-1; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int result = missingNumber(arr, n);
    cout<<"The missing value is " <<result;
    return 0;
}