#include<iostream>
#include<vector>
using namespace std;

// brute force approch
int lowerBound(vector<int> &arr, int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i] >= x) return i;
    }
    return n;
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
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    int result = lowerBound(arr, n , x);
    cout<<result;
    return 0;
}