#include<iostream>
#include<algorithm>
using namespace std;

// Brute force
// void rotateArrayBydPlace(int arr[], int n, int d){
//     d = d % n;
//     int temp[d];
//     for(int i=0; i<d; i++){
//         temp[i] = arr[i];
//     }
//     for(int i=d; i<n; i++){
//         arr[i-d] = arr[i];
//     }
//     for(int i=n-d; i<n; i++){
//         arr[i] = temp[i-(n-d)];
//     }
// }

// Optimal approch

void rotateArrayBydPlace(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter value of d : ";
    cin>>d;
    rotateArrayBydPlace(arr, n, d);
    cout<<"Rotated array is : ";
    for(int i=0;i<n; i++){
        cout<<arr[i] <<" ";
    }
    return 0;
}