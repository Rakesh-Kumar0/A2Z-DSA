#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;


// Function to count how many partitions are needed
int countPartition(vector<int> &arr, int maxsum){
    int partition = 1;
    int subarraySum = 0;
    for(int i=0; i<arr.size(); i++){
        if((subarraySum + arr[i]) <= maxsum){
            subarraySum += arr[i];
        }
        else{
            partition++;
            subarraySum = arr[i];
        }
    }
    return partition;
}

// brute force approch
// Function to find the minimum time to paint all boards using at most k painters
// int findtime(vector<int> &arr, int n, int painter){
//     // If students are more than books, allocation is impossible.
//     if(painter > n) return -1;
//     // Minimum possible answer is the largest book.
//     int low = *max_element(arr.begin(), arr.end());

//     // Maximum possible answer is the sum of all pages.
//     int high = accumulate(arr.begin(), arr.end(), 0);
//     for(int i=low; i<=high; i++){
//         int cntPainter = countPainter(arr, i);
//         if(cntPainter == painter) return i;
//     }
//     return -1;
// }


// binary search
int findSubarrayAum(vector<int> &arr, int n, int k){
   int low = *max_element(arr.begin(), arr.end());
   int high = accumulate(arr.begin(), arr.end(), 0);
   while(low <= high){
    int mid = low +(high - low)/2;
    int cntpart = countPartition(arr, mid);
    if(cntpart > k) low = mid + 1;
    else high = mid - 1;
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
    int k ;
    cout<<"Enter the numbers of subarray: ";
    cin>>k;
    int result =findSubarrayAum(arr, n, k);
    cout<<result;
    return 0;
}