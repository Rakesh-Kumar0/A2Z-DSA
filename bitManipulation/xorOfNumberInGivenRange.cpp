#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
int xorInRange(int n){
    int ans = 0;
    for(int i=1; i<=n; i++){
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
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    int result = xorInRange(n);
    cout<<result;
    return 0;
}