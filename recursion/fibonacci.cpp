#include<iostream> 
using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1) return n;
    // if(n<=1) return n;
    return fibonacci(n -1) + fibonacci(n - 2);
}

int main(){

    int t; 
    cout<<"Enter number of testcases : ";
    cin >>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter value of n : ";
        cin>>n;
        for(int j=0; j<n; j++){
            cout<<fibonacci(j) <<" " ;
        }
    }
    return 0;
}