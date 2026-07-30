#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// brute force
// double power(double x, int n){
//     // base case
//     if(n == 0 || x == 1.0) return 1;
//     long long temp = n; // to avoid integer overflow
//     if(n < 0){
//         x = 1/x;
//         temp = -1 *1LL* n; // make n positive
//     }
//     double ans = 1;
//     for(long long i=1; i<=temp; i++){
//         ans = ans * x;
//     }
//     return ans;
// }

// using recurssion
double power(double x, long long n){
    // base case
    if(n == 0) return 1.0;
    if(n == 1) return x;
    if(n % 2 == 0){
        return power(x*x, n/2);
    }
    return x* power(x, n-1);
}
double myPower(double x, int n){
    if(n < 0) return (1.0 /power(x, -1*n));
    return power(x , n);
}
int main(){
    double x;
    cout<<"Enter base number : ";
    cin>>x;
    int n;
    cout<<"Enter power number : ";
    cin>>n;
    double result = myPower(x, n);
    cout<<result;
    return 0;
}