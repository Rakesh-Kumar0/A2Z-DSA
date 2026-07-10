#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// brute force approch
int singleElement(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        if(i ==0){
            if(arr[i+1] != arr[i]) return arr[0];
        }
        else if(i = n-1){
            if(arr[i] != arr[i-1]) return arr[n-1];
        }
        else{
            if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
        }
    }
    return 0;
}
// binary search


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