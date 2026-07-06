#include<iostream>
#include<vector>
using namespace std;

//brute force approch
// vector<int> repeatingAndMissingNumber(vector<int> &arr, int n){
//     int repeating = -1;
//     int missing = -1;
//     for(int i=1; i<=n; i++){
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j] == i){
//                 cnt++;
//             }
//         }
//         if(cnt == 2) repeating = i;
//         else if(cnt == 0) missing = i;
//         if(repeating != -1 && missing != -1) break;
//     }
//     return {repeating,missing};
// }

// better approch

// vector<int> repeatingAndMissingNumber(vector<int> &arr, int n){
//     int hash[n+1] = {0};
//     int repeating = -1;
//     int missing = -1;
//     for(int i=0; i<n; i++){
//         hash[arr[i]]++;
//     }
//     for(int i=1; i<=n; i++){
//         if(hash[i] == 2) repeating = i;
//         else if(hash[i] == 0) missing = i;
//         if(repeating != -1 && missing != -1) break;
//     }
//     return {repeating,missing};
// }

// optimal approch 1
vector<int> repeatingAndMissingNumber(vector<int> &arr, int n){
    long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1)*(2*n+1))/6;
    long long s = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s += arr[i];
        s2 += (long long)arr[i]*(long long)arr[i];
    }
    long long val1 = s - sn;
    long long val2 = s2 - s2n;
    val2 = val2/val1;
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x , (int)y};
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
    vector<int> result = repeatingAndMissingNumber(arr, n);
    cout<<"{"<<result[0]<<" "<<result[1]<<"}";

    return 0;
}