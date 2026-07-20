#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
using namespace std;

// function that count number of days
int daysNeeded(vector<int> &arr, int capacity){
    int n = arr.size();
    int days = 1;
    int currentLoard = 0;
    for(int i=0; i<n; i++){
        if(arr[i] + currentLoard > capacity){
            days +=1;
            currentLoard = arr[i];
        }
        else {
            currentLoard +=arr[i];
        }
    }
    return days;
}

// Brute force approch
 int shipWithinDays(vector<int> &arr, int day){
    // Find maximum weight as minimum capacity
    int left = *max_element(arr.begin(), arr.end());
    // Find total sum as maximum capacity
    int right = accumulate(arr.begin(), arr.end(), 0);
    for(int capacity=left; capacity<=right; capacity++){
        int needed = daysNeeded(arr, capacity);
        if(needed <= day ){
            return capacity;
        }
    }
    return right;

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
    int day ;
    cout<<"Enter number of day required : ";
    cin>>day;
    int result = shipWithinDays(arr,day);
    cout<<result;
    return 0;
}