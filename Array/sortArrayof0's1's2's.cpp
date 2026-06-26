#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force approch

// void sortArrayofZeroOneTwo(vector<int> &arr, int n){
//     sort(arr.begin(), arr.end());
// }

// Better approch
void sortArrayofZeroOneTwo(vector<int> &arr, int n){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) cnt0 ++;
        else if(arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i=0; i<cnt0; i++){
        arr[i] = 0;
    }
    for(int i=cnt0; i<cnt0+cnt1; i++){
        arr[i] = 1;
    }
    for(int i=cnt0+cnt1; i<n; i++){
        arr[i] = 2;
    }
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