#include<iostream>
using namespace std;

int linearSearch(int arr[], int n ,int num){
    for(int i=0; i<n; i++){
        if(arr[i] == num) return i;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int num;
    cout<<"Enter the value of num : ";
    cin>>num;

    int result = linearSearch(arr, n, num);
    cout<<"The index of matching number is "<<result;
    return 0;
}