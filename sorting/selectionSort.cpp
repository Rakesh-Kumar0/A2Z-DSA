#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int mini = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
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
    selectionSort(arr, n);
    cout<<"Sorted array is : ";
    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }
    return 0;
}