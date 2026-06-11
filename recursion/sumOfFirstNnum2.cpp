#include<iostream>
using namespace std;

int printSum(int n){
    if(n == 0) return 0;
    return n + printSum(n - 1);
}

int main(){
    int t;
    cout<<"Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter value of n : ";
        cin>>n;
        int result = printSum(n);
        cout<<result <<endl;
    }
    return 0;
}