#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// function to print all subsequence
int printS(int index, vector<int> &ds, vector<int> &arr, int n, int s, int sum){

    // base case
    if(index == n){
        // if condition satisfied
        if(sum == s){
            return 1;
        }
        // if condition not satisfied
        else return 0;
    }
    ds.push_back(arr[index]);
    sum += arr[index];
    int left = printS(index+1, ds, arr, n, s, sum);
    ds.pop_back();
    sum -=arr[index];
    int right = printS(index+1, ds, arr, n, s, sum);
    return left + right ;
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
    vector<int> ds;
    int s;
    cout<<"Enter vlaue of s : ";
    cin>>s;
    int result = printS(0, ds, arr, n, s, 0);
    cout<<result;
    return 0;
}