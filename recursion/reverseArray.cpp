#include<iostream>
#include<algorithm>
using namespace std;

void reverseArry(int arr[], int l, int r){
    if(l >= r) return ;
    swap(arr[l], arr[r]);
    reverseArry(arr, l+1, r-1);
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cout <<"Enter size of an array : ";
        cin >>n;
        int arr[n];
        cout<<"Enter elements of an array : ";
        for(int j=0; j<n; j++){
            cin>>arr[j];
        }
        reverseArry(arr, 0 , n-1);
        for(int j =0 ;j<n; j++){
            cout<<arr[j] <<" ";
        }
        cout << endl;
    }
    return 0;
}