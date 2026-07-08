#include<iostream>
#include<vector>
using namespace std;

// Recursive code
int binarySearch(vector<int> &arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(target == arr[mid]) return mid;
    else if(target > arr[mid]){
        return binarySearch(arr, mid+1, high, target);
    }
    else {
        return binarySearch(arr, low, mid-1, target);
    }
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
    int target;
    cout<<"Enter value of target : ";
    cin>>target;
    int result = binarySearch(arr, 0, n-1, target);
    cout<<result;
    return 0;
}