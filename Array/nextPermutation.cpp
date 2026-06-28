#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Better Approch
void nextPermutation(vector<int> &arr, int n){
    next_permutation(arr.begin(), arr.end());
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

    nextPermutation(arr, n);
    for(auto it : arr){
        cout<<it <<" ";
    }
    return 0;
}