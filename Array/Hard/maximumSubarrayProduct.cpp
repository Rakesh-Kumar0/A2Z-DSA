#include<iostream>
#include<vector>
using namespace std;

//brute force approch
int maximumSubarrayProduct(vector<int> &arr, int n){
    int maxPro = arr[0];
    for(int i=0; i<n; i++){
        int product = 1;
        for(int j=i; j<n; j++){
            product = product * arr[j];
            maxPro = max(maxPro, product);
        }
    }
    return maxPro;
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
    int result = maximumSubarrayProduct(arr, n);
    cout<<result;

    return 0;
}