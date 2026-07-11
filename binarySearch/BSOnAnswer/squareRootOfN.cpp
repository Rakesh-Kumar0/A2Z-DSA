#include<iostream>
#include<algorithm>
using namespace std;

// brute force 
// int squareRoot(int n){
//     int ans = 1;
//     for(int i=1; i<=n; i++){
//         if(i * i <=n) ans = i;
//         else break;
//     }
//     return ans;
// }

// binary search
int squareRoot(int n){
    int ans = 1;
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
   

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int result = squareRoot(n);
    cout<<result;
    return 0;
}