#include<iostream>
using namespace std;

int factorial(int n){
    if(n ==0 || n == 1) return 1 ;
    return n * factorial(n - 1);
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin >>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter value of n : ";
        cin>>n;
        int result = factorial(n);
        cout<<result <<endl;
    }
    return 0;
}