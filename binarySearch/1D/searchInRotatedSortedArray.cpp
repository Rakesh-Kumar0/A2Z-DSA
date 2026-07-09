#include<iostream>
#include<vector>
using namespace std;

// brute force approch
int searchInRotatedSortedArray(vector<int> &arr, int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
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
    int result = searchInRotatedSortedArray(arr, n , x);
    cout<<result;
    return 0;
}