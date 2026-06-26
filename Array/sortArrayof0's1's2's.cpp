#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force approch

void sortArrayofZeroOneTwo(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
}

int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an array of 0's 1's and 2's : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sortArrayofZeroOneTwo(arr,n);
    for(auto it : arr){
        cout<<it <<" ";
    }
    return 0;
}