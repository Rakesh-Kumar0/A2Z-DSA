#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

// brute force approch
int kthMissingNumber(vector<int> &arr, int k){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
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
    int k ;
    cout<<"Enter the value of k : ";
    cin>>k;
    int result = kthMissingNumber(arr, k);
    cout<<result;
    return 0;
}