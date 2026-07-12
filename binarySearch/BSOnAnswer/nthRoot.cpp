#include<iostream>
#include<algorithm>
using namespace std;

// binary search
int power(int mid,int n, int m){
    int ans = 1;
    for(int i=0; i<n; i++){
        ans = ans * mid;
        if(ans>m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int nthRoot(int m, int n){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid  = (low + high)/2;
        int midN = power(mid,n,m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
   

int main(){
    int m;
    cout<<"Enter the number : ";
    cin>>m;
    int n;
    cout<<"Enter root number : ";
    cin>>n;
    int result = nthRoot(m,n);
    cout<<result;
    return 0;
}