#include<iostream>
#include<vector>
#include<map>
using namespace std;

// brute force approch
// int countSubArrayWithXORasK(vector<int> &arr, int n, int k){
//    int cnt = 0;
//    for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int XOR = 0;
//             for(int k=i; k<=j; k++){
//                 XOR = XOR ^ arr[k];
//             }
//             if(XOR == k) cnt++;
//         }
//    }
//    return cnt;

// }

// better approch

// int countSubArrayWithXORasK(vector<int> &arr, int n, int k){
//    int cnt = 0;
//    for(int i=0; i<n; i++){
//         int XOR = 0;
//         for(int j=i; j<n; j++){
//             XOR = XOR ^ arr[j];
//             if(XOR == k) cnt++;
//         }
//    }
//    return cnt;

// }

// optimal approch

int countSubArrayWithXORasK(vector<int> &arr, int n, int k){
   int xr = 0;
   int cnt = 0;
   map<int, int> mpp;
   mpp[xr]++;
   for(int i=0; i<n; i++){
        xr = xr^arr[i];
        int x = xr ^ k;
        cnt = cnt + mpp[x];
        mpp[xr]++;
   }
   return cnt;

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
    int result = countSubArrayWithXORasK(arr, n, k);
    cout<<result;
    return 0;
}