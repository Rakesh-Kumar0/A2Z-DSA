#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Better approch
int longestSubarrayWithSumK(vector<int> &arr, int n, long long k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
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
    cout<<"Enter value of k : ";
    cin>>k;

    int result = longestSubarrayWithSumK(arr, n, k);
    cout<<result;
    return 0;
}