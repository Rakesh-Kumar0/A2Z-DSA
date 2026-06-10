#include<iostream>
using namespace std;

void divisor(int num){
    for(int i=1; i<=num; i++){
        if(num % i == 0){
            cout<< i << endl;
        }
    }
}

int main(){

    int t;
    cout<<"Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int num;
        cout << "Enter number : ";
        cin>>num;
        divisor(num);
    }
    return 0;
}