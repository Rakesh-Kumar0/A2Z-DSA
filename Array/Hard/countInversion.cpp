#include<iostream>
#include<vector>
using namespace std;

//brute force approch
int countInversion(vector<int> &arr, int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements of an ayyar : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int result = countInversion(arr, n);
    cout<<result;

    return 0;
}