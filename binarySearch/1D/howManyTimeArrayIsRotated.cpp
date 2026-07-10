#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// binary search
int minimumInRotatedSortedArray(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
        }
        if(arr[low] <= arr[mid]){
            if(arr[low]< ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else {
            high = mid-1;
            if(arr[mid]<ans){
                index = mid;
                ans = arr[mid];
            }
        }
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
    
    int result = minimumInRotatedSortedArray(arr, n );
    cout<<result;
    return 0;
}