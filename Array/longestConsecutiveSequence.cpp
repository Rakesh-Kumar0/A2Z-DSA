#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// brute force approch
// linear search function
// bool ls(vector<int> &arr, int num){
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i] == num) return true;
//     }
//     return false;
// }

// int longestConsecutiveSequence(vector<int> &arr, int n){
//     int longest = 1;
//     for(int i=0; i<n; i++){
//         int x = arr[i];
//         int cnt = 1;
//         while(ls(arr,x+1) == true){
//             x = x+1;
//             cnt++;
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;
// }

// better approch
int longestConsecutiveSequence(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int longest = 1;
    int cnt = 0;
    int lastSmaller = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]-1 == lastSmaller){
            cnt++;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}
// Optimal approch


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

    int result = longestConsecutiveSequence(arr, n);
    cout<<result;
    return 0;
}