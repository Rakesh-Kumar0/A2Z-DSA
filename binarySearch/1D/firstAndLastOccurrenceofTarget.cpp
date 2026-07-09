#include<iostream>
#include<vector>
using namespace std;

// brute force approch
// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int target){
//     int first = -1;
//     int last = -1;
//     for(int i=0; i<n; i++){
//         if(arr[i] == target){
//             if(first == -1) first = i;
//             last = i;
//         }
//     }
//     return {first, last};
// }

// binary Search

// int lowerBound(vector<int> &arr, int n, int target){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low <= high){
//         int mid = (low+high)/2;
//         if(arr[mid] >= target){
//             ans = mid;
//             high = mid - 1;
//         }
//         else low = mid + 1;
//     }
//     return ans;
// }

// int upperBound(vector<int> &arr, int n, int target){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low <= high){
//         int mid = (low+high)/2;
//         if(arr[mid] > target){
//             ans = mid;
//             high = mid - 1;
//         }
//         else low = mid + 1;
//     }
//     return ans;
// }
// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int target){
//     int lb = lowerBound(arr,n,target);
//     if(lb == n || arr[lb] != target) return {-1, -1};
//     return {lb, upperBound(arr,n,target)-1};
// }


// without use of lowerBound and upperBoud
int firstPosition(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1 ;
    }
    return first;
}

int lastPosition(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            last = mid;
            low  = mid + 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid -1 ;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int target){
    int first = firstPosition(arr, n, target);
    if(first == -1) return {-1, -1};
    int last = lastPosition(arr,n,target);
    return {first, last};
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
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    pair<int, int> result = firstAndLastPosition(arr, n , x);
    cout<<"{"<<result.first<<" "<<result.second<<"}";
    return 0;
}