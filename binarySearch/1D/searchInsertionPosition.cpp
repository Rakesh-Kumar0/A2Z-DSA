#include<iostream>
#include<vector>
using namespace std;


// binary search
int searchInsertionPosition(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low >= high){
        int mid = (low + mid) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    int result = searchInsertionPosition(arr, n , x);
    cout<<result;
    return 0;
}