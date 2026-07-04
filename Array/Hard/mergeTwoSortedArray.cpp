#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// brute force approch
void merge(int arr1[], int arr2[], int n, int m){
    int arr3[n+m];
    int left=0;
    int right=0; 
    int index=0;
    while(left<n && right <m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else{
            arr3[index] = arr2[right];
            index++;
            right++;
        }
    }
    // for remaining elements in either array
    while(left < n){
        arr3[index++] = arr1[left++];
    }
    while(right < m){
        arr3[index++] = arr2[right++];
    }

    // put back again
    for(int i=0; i<n+m; i++){
        if(i<n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}

int main(){
    int n,m;
    cout<<"Enter the size of first array : ";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements of first array : ";
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    cout<<"Enter size of second array : ";
    cin>>m;
    cout<<"Enter the elements of second array : ";
    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    merge(arr1, arr2, n, m);
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0; i<m; i++){
        cout<<arr2[i] <<" ";
    }
    return 0;
}