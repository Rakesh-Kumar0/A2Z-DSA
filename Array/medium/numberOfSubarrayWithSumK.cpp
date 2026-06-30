#include<iostream>
#include<vector>
#include<map>
using namespace std;

//brute force approch
int numberOfSubarrayWithSumK(vector<int> &arr, int n, int k){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum +=arr[k];
            }
            if(sum == k){
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
    cout<<"Enter elements of an array : ";
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int k;
    cout<<"Enter target : ";
    cin>>k;
    int result = numberOfSubarrayWithSumK(arr, n, k);
    cout<<result;
    return 0;
}