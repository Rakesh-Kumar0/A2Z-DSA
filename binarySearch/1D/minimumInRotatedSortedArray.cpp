#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// binary search
int minimumInRotatedSortedArray(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid+1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid-1;
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