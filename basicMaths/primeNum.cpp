#include<iostream>
using namespace std;

void prime(int num){
    int cnt = 0;
    for(int i=1; i<=num; i++){
        if(num % i == 0) cnt++;
    }
    if(cnt == 2) cout<<num << "is prime" << endl;
    else cout<<num << "is not prime" << endl;
}

int main(){

    int t;
    cout << "Enter number of testcases : ";
    cin>>t;
    for(int i=0; i<t; i++){
        int num;
        cout<<"Enter number : ";
        cin >>num;
        prime(num);
    }
    return 0;
}