#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int minElement(vector<int> &arr, int n){
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
         mini = min(arr[i], mini);
    }
    return mini;
}

int maxElement(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
         maxi = max(arr[i], maxi);
    }
    return maxi;
}

bool possible(vector<int> &arr, int n, int day, int m, int k){
    int cnt = 0;
    int noOfBouquets = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfBouquets += (cnt/k);
            cnt = 0;
        }
    }
    noOfBouquets +=(cnt/k); 
    if(noOfBouquets >= m) return true;
    else return false;
}


// brute force
int noOfDays(vector<int> &arr, int n, int m, int k){
    if(n < m * k) return -1;
    for(int i=minElement(arr,n); i<= maxElement(arr,n); i++){
        if(possible(arr, n, i, m, k) == true) return i;
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
    int m;
    cout<<"Enter no. of bouquets required : ";
    cin>>m;
    int k;
    cout<<"Enter no. of adjacent flower required : ";
    cin>>k;
    int result = noOfDays(arr, n, m, k);
    cout<<result;
    return 0;
}