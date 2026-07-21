#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

// brute force approch
// Function to check if we can place all cows with at least distance 'd'
bool canWePlace(vector<int> &arr, int cows, int dist){
    int count = 1;
    int lastPos = arr[0]; // this is the position of previous cow
    for(int i=1; i<arr.size(); i++){
        if((arr[i] - lastPos) >= dist){
            count++;
            lastPos = arr[i];
        }
    }
    if(count >= cows) return true;
    else return false;
}

// Function to find maximum minimum distance using brute force
int aggresiveCow(vector<int> &arr, int cows){
    sort(arr.begin(), arr.end());
    for(int i=1; i<=(arr[arr.size()-1] - arr[0]); i++){
        if(canWePlace(arr, cows, i) == true) continue;
        else return (i - 1);
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
    int cows ;
    cout<<"Enter the numbers of cows : ";
    cin>>cows;
    int result =aggresiveCow(arr, cows);
    cout<<result;
    return 0;
}