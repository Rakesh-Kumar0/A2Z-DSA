#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;

// finding maximum in array
int maxElement(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > maxi){
            maxi = max(maxi, arr[i]);
        }
    }
    return maxi;
}
// function that find total hour
long long totalHour(vector<int> &arr, int k, int n){
    long long totalhour = 0;
    for(int i=0; i<n; i++){
        totalhour += ceil((double)arr[i]/(double)k);
    }
    return totalhour;
}

int kokoEatingBanana(vector<int> &arr, int hour, int n){
    int low = 1;
    int high = maxElement(arr, n);
    while(low <= high){
        int mid = low + (high - low) / 2;
        long long totalhrs = totalHour(arr, mid, n);
        if(totalhrs <= hour) high = mid - 1;
        else low = mid + 1;
    }
    return low;
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
    int hour;
    cout<<"Enter the number of hour : ";
    cin>>hour;
    int result = kokoEatingBanana(arr, hour, n);
    cout<<result;
    return 0;
}