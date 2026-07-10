#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// brute force approch
// int singleElement(vector<int> &arr, int n){
//     for(int i=0; i<n; i++){
//         if(i ==0){
//             if(arr[i+1] != arr[i]) return arr[0];
//         }
//         else if(i = n-1){
//             if(arr[i] != arr[i-1]) return arr[n-1];
//         }
//         else{
//             if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
//         }
//     }
//     return 0;
// }

// binary search
int singleElement(vector<int> &arr, int n){
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low <=high){
        int mid  = (low + high)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
        // eliminate left half
        if((mid%2 == 1 && arr[mid-1] == arr[mid]) || (mid %2==0 && arr[mid] == arr[mid+1])) low = mid + 1;
        // eliminate right half
        else high = mid-1;
    }
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
    
    int result = singleElement(arr, n );
    cout<<result;
    return 0;
}