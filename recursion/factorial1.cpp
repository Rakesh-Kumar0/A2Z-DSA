#include<iostream>
using namespace std;

void factorial(int i, int fact){
    if(i <=1){
        cout<<fact << endl;
        return ;
    }
    factorial(i-1, fact * i);
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin >>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter value of n : ";
        cin>>n;
        factorial(n,1);
    }
    return 0;
}