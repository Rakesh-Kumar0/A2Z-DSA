#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// brute force approch
int peakElement(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        if((i==0 || arr[i-1]<arr[i]) && (i == n-1 || arr[i] > arr[i+1])) return arr[i];
    }
    return -1;
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
    
    int result = peakElement(arr, n );
    cout<<result;
    return 0;
}