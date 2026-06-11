#include<iostream>
#include<algorithm>
using namespace std;

void reverseArry(int arr[], int n, int l){
    if(l >= n / 2) return ;
    swap(arr[l], arr[n-l-1]);
    reverseArry(arr, n, l+1);
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
        reverseArry(arr, n , 0);
        for(int j =0 ;j<n; j++){
            cout<<arr[j] <<" ";
        }
        cout << endl;
    }
    return 0;
}