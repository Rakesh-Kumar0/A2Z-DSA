#include<iostream>
#include<algorithm>
using namespace std;

// brute force 
int squareRoot(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        if(i * i <=n) ans = i;
        else break;
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