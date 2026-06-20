#include<iostream>
using namespace std;

int largestElement(int arr[], int n){
    int largestElement = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > largestElement){
            largestElement = arr[i];
        }
    }
    return largestElement ;
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
    int result = largestElement(arr, n);
    cout<<"largest element is " << result;
    return 0;
}