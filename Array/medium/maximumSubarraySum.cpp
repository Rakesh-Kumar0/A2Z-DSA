#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;


// optimal using kadane's algorithm

int maximumSubArraySum(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }

    }
    return maxi;
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
    int result = maximumSubArraySum(arr, n);
    cout<<result;
    return 0;
}