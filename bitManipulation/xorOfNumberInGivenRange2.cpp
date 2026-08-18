#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
int xorInRange(int l, int r){
    int ans = 0;
    for(int i=l; i<=r; i++){
        ans = ans^i;
    }
    return ans;
}

// optimal solution
// int xorInRange(int n){
//     if(n%4 == 1) return 1;
//     else if(n%4 == 2) return n+1;
//     else if(n%4 == 3) return 0;
//     else return n;
// }
int main(){
    int l;
    cout<<"Enter left value  : ";
    cin>>l;
    int r;
    cout<<"Enter right value : ";
    cin>>r;
    int result = xorInRange(l, r);
    cout<<result;
    return 0;
}