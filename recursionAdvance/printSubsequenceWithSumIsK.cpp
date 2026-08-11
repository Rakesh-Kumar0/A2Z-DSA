#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// function to print all subsequence
void printS(int index, vector<int> &ds, vector<int> &arr, int n, int s, int sum){

    // base case
    if(index == n){
        if(sum == s){
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
        }
        return ;
    }
    ds.push_back(arr[index]);
    sum += arr[index];
    printS(index+1, ds, arr, n, s, sum);
    ds.pop_back();
    sum -=arr[index];
    printS(index+1, ds, arr, n, s, sum);
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
    printS(0, ds, arr, n, s, 0);
    return 0;
}