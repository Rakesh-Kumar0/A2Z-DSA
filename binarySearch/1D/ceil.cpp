#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= x){
            ans = arr[mid];
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
    int result = floor(arr, n , x);
    cout<<result;
    return 0;
}