#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

// brute force approch
// int smallestDivisor(vector<int> &arr, int threshold){
//     int maxi = *max_element(arr.begin(), arr.end());
//     for(int div=1; div<=maxi; div++){
//         int sum = 0;
//         for(int i=0; i<arr.size(); i++){
//             sum = sum + ceil((double)arr[i]/(double)div);
//         }
//         if(sum <= threshold) return div;
//     }
//     return -1;
// }

//binary search
int sumOfDivisor(vector<int> &arr, int div){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum +=ceil((double)arr[i]/(double)div);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int threshold){
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    while(low <= high){
        int mid = low + (high - low)/2;
        if(sumOfDivisor(arr, mid) <= threshold) high = mid -1;
        else low = mid+1;
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
    int threshold ;
    cout<<"Enter threshold value : ";
    cin>>threshold;
    int result = smallestDivisor(arr, threshold);
    cout<<result;
    return 0;
}