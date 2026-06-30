#include<iostream>
#include<vector>
using namespace std;

void rotateArrayByOnePlace(vector<int> &arr, int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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
    cout<<"Ratated array is : ";
    rotateArrayByOnePlace(arr, n);
    for(auto it : arr){
        cout<<it <<" ";
    }
    return 0;
}