#include<iostream>
#include<vector>
using namespace std;

// brute force approch
// int searchInRotatedSortedArray(vector<int> &arr, int n, int target){
//     for(int i=0; i<n; i++){
//         if(arr[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }

// binary search
int searchInRotatedSortedArray(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        // left sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid -1;
            }
            else low = mid + 1;
        }
        // right sorted
        else {
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else high = mid -1;
        }
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
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    int result = searchInRotatedSortedArray(arr, n , x);
    cout<<result;
    return 0;
}