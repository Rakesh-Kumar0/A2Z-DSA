#include<iostream>
#include<vector>
using namespace std;

int buyAndSellStock(vector<int> &arr, int n){
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=1; i<n; i++){
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
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
    int result = buyAndSellStock(arr, n);
    cout<<result;
    return 0;
}