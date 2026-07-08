#include<iostream>
#include<vector>
using namespace std;

// iterative code
int binarySearch(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else {
            high = mid - 1;
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
    int target;
    cout<<"Enter value of target : ";
    cin>>target;
    int result = binarySearch(arr, n, target);
    cout<<result;
    return 0;
}